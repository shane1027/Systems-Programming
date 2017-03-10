Checklist for Exam 2
----

Outline of key concepts on exam.

## Topics:

### Generating Documents

1. What are the advantages and disadvantages of using command line tools such as pdflatex and gnuplot to create documents?

2. How would you use ImageMagick to:

    - Convert a PNG image to JPG?

    - Resize a PNG image?

    - Blend two PNG images?

    - Create a GIF from a series of PNG images?

 
### Scraping the Web

#### Concepts

##### How is Python different from the Bourne shell? How is it similar?

##### How do we manage control flow in Python? How do we utilize these constructs?

    - Conditionals

    - Loops

    - Exceptions

    - Functions

##### What data structures do we have in Python? What are their basic operations?

    - Lists

    - Dictionaries

    - Sets

##### How do we do the following in Python?

    - Process command-line arguments

    - Read and write files

    - Read standard input

    - Use regular expressions

    - Check if a file exists

    - Execute an external command

    - Fetch data from the web

    - Process JSON data from the web

##### Sample Questions

##### Given the following Unix pipelines, write Python code that accomplishes the same task.

cat /etc/passwd | cut -d : -f 1 | grep d$ | wc -l

cat /etc/passwd | cut -d : -f 3 | grep -E '^[0-9]{2}$' | sort | uniq

curl -s http://sprunge.us/bJIN | cut -d , -f 3 | grep -Eo '^[^aeoiu]*@.*'

curl -s http://sprunge.us/bJIN | grep -Eo '^B.*' | cut -d , -f 1 | sort

who | sed -rn 's|.*\((.*)\).*|\1|p' | sort | uniq

ls -l /etc | awk '{print $2}' | sort | uniq -c


### Processing Data

##### What is the difference between procedural and functional programming?

    - What are some benefits of functional programming?

    - How is functional programming related to the Unix Philosophy?

##### How do we use map, filter, reduce, and lambda to do functional programming in Python?

##### How do we use list comprehensions to do functional programming in Python?

##### What is an iterator and how is it different from a list?

    An iterator is an iterable, consumable stream of data.  A list is not
    consumed upon access, can be indexed, and an iterator doesn't return
    anything but the next value.

    - What are the advantages of using an iterator?

        Don't have to store as much in memory at once, can distribute work.

    - What are the disadvantages of using an iterator?
        
        They cannot be indexed (no random access, only next thing)

##### What is a generator and how it is different from a list?

    - What does the yield command do?

        Pauses the execution of the current function and saves its state after
        returning a value if specified.  Control is given back to calling func.

    - Why would we use a generator over a list?

        We wouldn't have to store all of the list in memory, and can make a
        generator function that represents an infinite number of items.

    - How do we convert a list comprehension to a generator comprehension?

##### What is the difference between concurrency and parallelism?

    *Concurrency* is about **structure** - breaking a program into subtasks
    that could happen at the same time.  Also when multiple tasks can start, run,
    and complete in an
    overlapping time period (although they don't necessarily have to be running
    at the same time) whereas *Parallelism* is when tasks can literally run at
    the same time thanks to available resources (typically brains, cores).
    
    C: composition of independently executing computations, i.e. generator
    starting and idling when other things are going on until called again.
    Both the generator function and main function are executing at the same
    time period, and have separate program states. (Running at same time, not
    necessarily executing at same time)

    Get parallelism for free when programs are structued with concurrency!!
    
    Examples:  Concurrency occurs when multitasking with a single-core
    machine, and Parallelism on a multicore processor.

    - What are some problems with concurrency?

        Overhead - need to manage processes

        Contention / *Deadlock* - multiple processes vying for the same resource.

        Race conditions - program depends on certain processes occuring in
        order

        Dealing with data can be finnicky - i.e. two processes updating the
        same data element and therefore one update is lost, a process accessing
        data before a different process rolls back its contribution to the
        data, and accessing large blocks of data during which some of it is
        changed by another process.

    - How does functional programming help enable concurrency and avoid these problems?

        Refined answer: functional programming eliminates side effects - data
        structures are immutable and therefore there are no interaction
        problems between multiple processes running simultaneously that mutate
        or access data.

        Race conditions cannot occur because tasks are inherently independent.



        Also: since functional programming uses mathematical functions
        evaluated with arguments (and thus anytime a function is called with
        the same arguments it returns the same result), parts of functional
        programs can be evaluated out of order without changing the outcome.
        Thus we can parallelize functional programs without worrying about the
        order in which different parts are completed by the pool, as long as it
        all gets done!

        Possibly concurrent vs inherently sequential.

        Old answer: Functional programming does not pass objects of data between processes
        or functions, does not rely on outside sources of data besides its
        arguments, and is very clear in only returning or changing the one
        item each function is designed to effect.  This eliminates problems 
        with functions dealing with lots of different data or implementing more
        than one logical step in a program, enabling concurrency.

    - What does it mean for a problem to be data parallel or embarrassingly parallel?

        All items can be processed independently of each other.

        A data parallel job implements a function on some set of data and 
        can be divided equally among all available processors.
        The same task is to be performed on each data element, and
        thus each processor receives an equal number or data elements that need
        to be evaluated and carries out such evaluations.

        An embarrasingly parallel job is one that is inherently parallel -
        little to no effort is needed to separate the problem into a number of
        parallel tasks.  Such problems typically do not need much communication
        between parallel taks or the results.

    

##### What is MapReduce?

    A programming model for processing and generating large data sets.  It
    hides parallelization / multiprocessing behind a layer of abstraction, has 
    fault-tolerance, effective data distribution, usually includes load balancing.

    Use higher-order functions to take advantage of data independence.

    - What problem is MapReduce trying to solve?
        
        Applying a function or manipulation to a large set of data.

    - What are the three phases of a typical MapReduce workflow?

        Map - apply a function or filter to the input data, generate key /
        value pairs

        Shuffle / Sort - redistribute data across multiple nodes in related
        groups

        Reduce - aggregate the results at each node

    - How would you implement a simple MapReduce application such as word count?

        - Apply map function to each input pair to generate intermediate pairs

        - Shuffle so that each intermediate pair w/ same key sent to same
          reducer

        - Sort corresponding intermediate pairs by key, apply reduce function
          to generate output pairs

        - If necessary, merge output pairs, and for word count this is
          necessary

