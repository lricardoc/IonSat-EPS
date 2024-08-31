% Define parameters
C = 100; % Heat capacity (example value)
sigma = 5.67e-8; % Stefan-Boltzmann constant
Aeff = 7*0.00265*0.92; % Effective area (example value)
A = 7*0.00265; % Area (example value)

% Load or define the stored values for Qtot
% Assuming thermal.T_plusX is a column vector of values sampled every 1 second
%thermal.T_plusX = [...]; % Replace with your actual data
time_samples = 0:length(thermal.pX)-1; % Time points corresponding to samples

% Define the function for Qtot using interpolation
Qtot = @(t) interp1(timesec, thermal.pX, t, 'linear', 'extrap');

% Define the differential equation
dTempdt = @(t, T) (-sigma * Aeff * T^4 + Qtot(t) * A) / C;

% Initial condition
T0 = 280; % Initial temperature (example value)

% Time span
tspan = [0 timesec(end)]; % Example time span from 0 to 10 seconds

% Solve the differential equation using ode45
[t, T] = ode45(dTempdt, tspan, T0);

% Plot the results
figure;
plot(t, T-273);
xlabel('Time (s)');
ylabel('Temperature (°C)');
title('Temperature vs Time');
grid on;

%% With function
% Example parameters
C = 100; % Heat capacity
Aeff = 7*0.00265*0.92; % Effective area
A = 7*0.00265; % Area
%thermal.pX = [...]; % Your thermal data
timesec = 0:length(thermal.pX)-1; % Time points
T0 = 280; % Initial temperature

% Call the function
[t,T] = calc_temp_SP(C, Aeff, A, thermal.pX, timesec, T0);

% Plot the results
figure;
plot(t, T-273);
xlabel('Time (s)');
ylabel('Temperature (°C)');
title('Temperature vs Time');
grid on;