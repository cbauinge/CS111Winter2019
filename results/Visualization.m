clear
clc
close all


Nodes = csvread('nodes_result');

T = csvread('simplices_result');

values = csvread('solution_result');
values = reshape(values, sqrt(size(values, 1)), sqrt(size(values, 1)));

plotvals = zeros(size(values, 1) +2, size(values, 2) +2);

plotvals(2:end-1, 2:end-1) = values;
plotvals = plotvals(:);

%figure
%plot(Nodes(:, 1), Nodes(:, 2), 'x')


figure
triplot(T(:, 1:3)+1, Nodes(:, 1), Nodes(:, 2))

figure 
trisurf(T(:, 1:3)+1, Nodes(:, 1), Nodes(:, 2), plotvals);