function [fraction_eclipse] = eclipsefraction(h,beta)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
Re=6378;        %earth radius
betaprima=180/pi*asin(Re/(Re+h));
if abs(beta)<betaprima
    fe=1/(pi)*acos(sqrt(h^2+2*Re*h)/((Re+h)*cos(beta)));
else 
    fe=0;
end
fraction_eclipse=fe;
end

