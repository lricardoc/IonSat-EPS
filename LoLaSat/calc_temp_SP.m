function [time_dif,T] = calc_temp_SP(C, Aeff, A, thermal, timesec, T0)
%Calculates temperature of a Solar Panel, T is in K.
    % Define constants
    sigma = 5.67e-8; % Stefan-Boltzmann constant

    % Define the function for Qtot using interpolation
    Qtot = @(t) interp1(timesec, thermal, t, 'linear', 'extrap');

    % Define the differential equation
    dTempdt = @(t, T) (-sigma * Aeff * T^4 + Qtot(t) * A) / C;

    % Time span
    tspan = [0 timesec(end)]; % Time span from 0 to the end of timesec

    % Solve the differential equation using ode45
    [time_dif, T] = ode45(dTempdt, tspan, T0);
end