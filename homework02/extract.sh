#!/bin/sh

# shell script to unpack a list of files with various extensions

unpack()
{

    case $EXTENSION in
        tgz)
            tar -xzvf $1
            ;;
        gz)        # gzip
            tar -xzvf $1
            ;;
        tbz)
            tar -xjvf $1
            ;;
        bz2)       # bzip2
            tar -xjvf $1
            ;;
        txz)
            tar -xJvf $1
            ;;
        xz)        # xz
            tar -xJvf $1
            ;;
        zip)
            unzip $1
            ;;
        jar)  
            unzip $1
            ;;
        *)
            echo "Unsupported file extension."
            return 1
            ;;
    esac

    return 0

}


##############
# Main Program 
##############

if [ "$#" -gt "0" ]; then
    echo "Number of input files: $#"
    for i in $(eval echo {1..$#})   # force variable to be expanded before {}
    do
            EXTENSION="${1##*.}"    # using two ## gives .gz instead of .tar.gz
            echo "Current file: $1"
            echo "Extension: $EXTENSION"
            unpack $1 $EXTENSION
            # `"$OUTPUT"`
            # echo "$OUTPUT"
            shift
    done
        echo "Thanks for using extract.sh!"
else
    echo "Please specify files to extract as arguments."
    echo "Usage: ./extract.sh archive1 archive2 ..."
fi

