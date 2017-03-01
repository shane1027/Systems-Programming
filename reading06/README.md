Reading 06
==========

A. What problem is MapReduce trying to solve?

Processing large sets of data that can be iterated over by dealing with data in
parallel over multiple nodes as a part of a cluster.  Pattern searching,
sorting, etc. in a distributed manner.

B. Describe the three phases of a typical MapReduce workflow.

Map - All nodes store the result of applying the mapped function onto the data.

Shuffle - Redistribute data to worker nodes based on map result to localize
data with the same key.

Reduce - Nodes process the redistributed data according to each key
simultaneously.
