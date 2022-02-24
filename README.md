# Assumptions 
- It assumes that the theater has 10 rows from 'A' to 'J', where A is the closest row to the screen and J is the farthest row from the screen, and has 20 seats per row ranging from 1 to 20, with 1 being the far left seat and 20 being the far right seat.
- It assumes that every reservation party must be seated at least 3 seats away from each other and/or at least 1 row away to maximize customer safety.
- It assumes that customer satisfaction is determined by earlier reservations sitting from the middle to the back of the theater and later reservations sitting towards the front of the theater.
- It assumes that each reservation can not reserve more than seats than the number of seats per row. In this case there can not be a reservation of more than 20 seats.

# Instructions
## Compiling the program
Run 
```
 make 
 ```
 on the terminal to compile the code

 ## Executing the program
 Run 
 ```
 ./main input.txt
 ```
to execute the program

The input.txt file contains identifers and the number of seats requested as follows:
```
R001 2
R002 4
R003 4
R004 3
```


## Expected Output
The output should be a list of seat allocations from these reservations optimized for customer satisfaction, customer safety, and theater space utilization.
