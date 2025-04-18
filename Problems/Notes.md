# Problems Notes

## Problem 1: Multiplication Table (1–10)
	- Used nested loops for rows and columns
	- Printed header in a separate function
	- Used another function to adjust spacing before each row
	- Can be improved by letting the user input the table range
	- No bugs or issues faced
---	
## Problem 2: Prime Numbers from 1 to N
	- Read a positive number from user using a loop  
	- Used an `enum` to define Prime and NotPrime states  
	- Checked primality by looping up to Number / 2  
	- Printed all prime numbers from 1 to N  
	- Function design was clean and modular  
	- Could be improved by optimizing the loop up to sqrt(N)
	- No bugs or confusion, logic was straightforward
---
## Problem 3 - Perfect Number Check
	- Checked if the number is perfect by calculating the sum of its divisors  
	- Used an `enum` to define Perfect and NotPerfect statuses  
	- Optimized the divisor check by looping up to Number / 2  
	- Displayed the result in a clean and readable format  
	- Could be optimized further using the fact that divisors come in pairs (sum of divisors optimization)
	- Used `auto` for automatic type deduction and `const` for immutability 
	- No issues encountered during the implementation