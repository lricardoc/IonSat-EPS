function [kcos] = kcosine(theta)
%KCOSINE Summary of this function goes here
%Kelly cosine
%   Detailed explanation goes here

th_s=abs(theta);
    if th_s<=pi/2
        kcos=0;
    end
    if th_s<17*pi/36
        kcos=(cos(1.059*th_s))^0.949;
    end

end


