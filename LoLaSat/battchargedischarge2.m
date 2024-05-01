function [Ibattery] = battchargedischarge2(input)
%Logic for charging, discharging
%   inputs are:
% input 1: the current load of the loads 
% input 2: the current generated at the ouput of the ACU 
% input 3: Maximum discharge current of the battery (input is positive) 
% input 4: Maximum charge current of the battery (input is positive)
% input 5: Battery voltage
% Compares both and decides a charging current
% output: Battery current, 
%                           (+) for discharging 
%                           (-) for charging 

iLoads = input(1);
iACU = input(2);
I_BD_max= input (3);
I_BC_max= -input (4);
Vbat= input (5);

Vfull=16.8/4;     %full battery charge
Vmax=16.6/4;      %maximum charge battery
Vnorm=14/4;       %battery normal voltage
Vsafe=13.4/4;      %minimum battery safe voltage
Vcrit=13/4;       %critical battery voltage

Ibattery = iLoads-iACU;
if Ibattery>I_BD_max
    Ibattery=I_BD_max;
end
if Ibattery<I_BC_max
    Ibattery=I_BC_max;
end

if Vbat>=Vfull && Ibattery<0  %fully charged
    Ibattery=0;
end
if Vbat>Vmax && Ibattery<-0.2  %trickle mode
    Ibattery=-.2;
end
if Vbat<Vcrit && Ibattery>0  %battery failure
    Ibattery=0;
end
if Vbat<Vsafe && Ibattery>0  %battery safe mode
    Ibattery=-iACU;
end

end

