# Emergency-Response-Shortest-Path-Project
Weighted Undirected Graph using Dijkstra's Algorithm to Find the Shortest Lowest-Weight Path

First responders have to get where they need to go as quickly as possible. Therefore, they must choose the route that minimizes their travel time. This minimization should consider three things: the distance to travel, the safest speed on each road, and the traffic conditions. For example, if two routes are the same length but the safe travel speed is higher on one than the other, the preferred route is the one with the higher speed. However, if traffic conditions are such that this higher-speed route is congested, it may make more sense to choose the lower-speed route that day. A modern city has several ways to obtain real-time traffic data. For this project, we are going to aggregate traffic data into a single number between 0 and 1 called the “adjustment factor”. The travel time between any two adjacent vertices is given by:

_T = d/(S*A)_

Where d is the distance between the vertices, in metres, S is the speed limit on the road connecting them, in m/s, and A is the adjustment factor. If A = 0, this means that the road is fully blocked and the time is infinite.

