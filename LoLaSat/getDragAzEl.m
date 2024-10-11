function [out] = getDragAzEl(u)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%first normalize the vectors
x=u(1:3)/norm(u(1:3));
y=u(4:6)/norm(u(4:6));
z=u(7:9)/norm(u(7:9));

% El = asin(z(1));
% A = acos(y(2));
% if x(2)<-0.01
%     Az = 2*pi-A;
% else
%     Az = A;
% end

El = -asin(x(3));
A = acos(y(2));
    if y(1)>0.01
        Az = 2*pi-A;
    else
        Az = A;
    end

out = [Az, El];
end