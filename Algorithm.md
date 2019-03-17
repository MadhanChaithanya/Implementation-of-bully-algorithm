## Algorithm

1.The election message is sent by the process which comes to know that coordinator is not responding.

2.The coordinator processes the respond to the process sending the acknowledgement message to all the processes.

3.The processes will respond the message by sending ok message.
Process with the highest priority will be chosen as the coordinator.

4.If the  bigger processes  do not reply then it will declare itself as the coordinator and send message to all.

5.Else the higher priority process will be the new coordinator.

6.If the higher priority process comes alive again then it  will be the coordinator again.

7.End
