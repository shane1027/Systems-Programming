#!/bin/sh

# use a function recursively to calculate a number factorial

factorial()
{

    if [ "$1" -gt "1" ]; then # as long as we haven't hit zero yet, continue
        i=`expr $1 - 1`         # subtract one to decrement
        j=`factorial $i`        # call the function w/ decremented value, which
                                # keeps on happening until we reach zero
        k=`expr $1 \* $j`       # multiply nth call by
                                # (n-1) call 
        echo $k                 # then echo that to
                                # (n-2) call, and so forth, until last call is
                                # reached. then we return k to calling code.
    else
        echo 1      # once we hit zero, return 1 to previous factorial() call
    fi

    return $k

}


while :
do
    echo "Enter a number:"
    read x
    result=`factorial $x`
    echo $result
done
