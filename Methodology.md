### The message is sent when the coordinate process fails in the system(coordinator process is the process which controls all the other processes).The election message is sent that the coordinator process is dead and so the election has begun. The process which comes to know first sends the message to all the other member processes. 

### The process which comes to know broadcasts a message to all the processes and all the processes reply by sending ok message the process elder to the process which comes to know that the coordinator if do not respond then that process becomes the new coordinator. 

### The process with the greatest priority is elected as the new coordinator process. 

### And the process which becomes the coordinator sends the message to all the other processes that i have become the new coordinator. 


