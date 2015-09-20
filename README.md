# redis-simulink
Example of a C Simulink S-Function block implementing a REDIS connector to interact with a REDIS server.

## Installation

Install HIREDIS.

- cd hiredis
- make & make install

## Compile REDIS S-function

(From matlab prompt)

- REDIS_compile

## Description

This model runs in an endless simulation sending commands to a REDIS server like follows (printing the server response):

Command 1) SET EURUSD:last 1.32343
Command 2) SET GBPJPY:last 186.432
Command 3) SET AUDUSD:last 0.71882

Command 4) GET EURUSD:last
Command 5) GET GBPJPY:last
Command 6) GET AUDUSD:last

Command 7) LPUSH mylist ITEM_1 ITEM_2 ITEM_3 ITEM_4 ITEM_5 ITEM_6 ITEM_7 ITEM_8 ITEM_9 ITEM_10
Command 8) LRANGE mylist 0 9

The model is split into 3 subsystems:

1) Command builder:

	- This Stateflow chart just constructs commands and send them to the REDIS connector block.

2) REDIS connector:

	This Block is composed by 2 blocks:

	- S-Function REDIS connector: 

		This block creates a connection with a REDIS server and send the commands that the Command builder block is sending to him. When this block receives a response from the REDIS server , it pushes 
	all the returned values (one by one) to the next block (Redis Response Queue) , which will store them until all the returned values has been flushed from the REDIS S-function connector.

	- Redis Response Queue: 
		
		This is a block that stores all the redis values returned by the redis server through the S-function block. When receiving the last value from a response it triggers a "RECEIVED" event.

3) Receptor

	- Block to simulate a receptor reading from the REDIS connector block.


## Pending

	The model is intended as an example. Code generation is not 100% ready for now.

## Credits

The Mad Hatter


