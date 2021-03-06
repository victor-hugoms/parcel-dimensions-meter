# Parcel's dimensions meter
This project creates a meter for the dimensions (and thus volume) of boxes (rectangular cuboids) by using ultrasonic sensors.
Potential use cases for this project includes logistics, where parcels' dimensions can be measured and, consequently, its volume. Than the shipping price can be estimated. The dimensions of the measured boxes can serve as input for the [Knapsack optimization problem](https://en.wikipedia.org/wiki/Knapsack_problem), where the objective is to maximize the amount (or value) of parcels to be delivered in a transportation truck (between network nodes or in last mile).

Este projeto cria um medidor de dimensões (e volume) de caixas usando sensores ultrasônicos. O projeto pode ser implementado, por exemplo, na logística para medir as caixas transportadas e realizar cobrança (por volume) ou a otimização do transporte (acoplando os resultados como entrada para o problema do Knapsack).


## Release plan
- v1 - with original Ultrasonic on Arduino
- v2 - add IoT layer
- v3 - improve Ultrasonic library