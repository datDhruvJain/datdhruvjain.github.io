# What is a Blockchain?

Let's take the word Blockchain and deconstuct it.

## A Block

The Block in the blockchain refers to the actual data container. Think of it as a package that you might recieve from Amazon when you order something online.

It has the actual product inside container, but the container itself has some information for the Delivery Person to know where to deliever it, any extra delivery instructions and information for Amazon's internal processing.

In a similiar way, A block contains the actual data, and some data for itself. The actual data in a cryptocurrency blockchain (like Bitcoin) would be the transaction details. All the extra information is stored in a segment called the "Block Header".

### The Block Header contains:
#### The Block version
This is to store the information about the software version and other such details.
#### Merkel Tree Root Hash
#### Time Stamp
#### nBits
#### Nonce
This is a special number that can be adjusted to change the complexity of the "Math problem" and hence the time taken to solve it. This particular data can help with differences in computing power over time.
#### Parent Block Hash
Each Block contains within itself, the hash value of the previous block.



## Steps invlolved in adding a block to the Blockchain

1. Nodes communicate with the blockchain network via a combination of private & public keys. The user uses its own private key to digitally sign its own transactions and then can access the network via the public key. Each signed transaction is broadcast by a node that makes the transaction.

2. The transaction is then verified by all nodes within the blockchain network except the node that makes the transaction.During this step, any invalid transactions are discarded. It's known as verification.

3. Mining is the third step in which every legitimate transaction is collected by the network nodes during a fixed time into a block and implements a proof-of-work to find a nonce for its block. Once a node finds a nonce, it broadcasts the block to all participating nodes.

4. Each node collects a newly generated block and confirms whether the block contains 
    a. legal transactions and 
    b. declares the accuracy of parent block by utilizing the hash value. 
After the completion of confirmation, nodes will add the block to the blockchain and apply the transactions to bring the blockchain up-to-date. In case, if the block is not confirmed, the projected block is rejected. This ends the existing mining round.
