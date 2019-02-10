clear
clc
close all


Nodes = csvread('nodes_Testdomain');

T = csvread('simplices_Testdomain');

%figure
%plot(Nodes(:, 1), Nodes(:, 2), 'x')


figure
triplot(T(:, 1:3)+1, Nodes(:, 1), Nodes(:, 2))