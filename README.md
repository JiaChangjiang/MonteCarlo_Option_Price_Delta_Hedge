# MonteCarlo_Option_Price_Delta_Hedge
MonteCarlo_Simulation_SharePrice_Option_Price_Delta_Hedge(vanilla,asian,barrier option)
In this project,the share class will simulate the set number of stock price paths and store the result in a vector.The result will be used in next steps to 
calculate the monte  price and delta by reference. I store the simulate results in Share class to avoid simulating the stock process for every option. If the expiry year is long, in Option Class the pathes can be simulated further.
the interest rate ,simulation_times are defined  as const in the Option_P1.h for changing easily.
the Barrier Option base class will store the code about monte carlo Price and Delta
the sub-class of Barrier Options are just interface.
this way will save a lot of time and easy to mange the code.

The demand for the code is in file project1
