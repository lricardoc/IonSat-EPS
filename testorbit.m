%% Run comparison simulation
%Run the simulation to produce output of the magnetic field over N orbits
%The orbits are assumed circular and at the inclination of the ISS in 2020

N_orbits = 1;

%The object is assumed submitted only to gravity and it's mass is m in kg

m = 10; %mass (kg)

%the time of the simulation will assume a LEO orbit with period of 90
%minutes

t_sim = N_orbits*90*60;

%use simulation time step that high balls typical magnetometer sampling
%rates for cubeSATs as well as relevant time scale of change for magnetic
%field effects on torque to 10 Hz

delta_t = 1; %simulation time step (seconds)

%Initialisation of Keplerian parameters
% % a = 6678; %semimajor axis (km)
% % e = 0; %eccentricity
% % i = 51.6; %inclination (degrees)
% % O = 185; %Right ascencion of the right ascending node (degrees)
% % o = 90; %Argument of the perigee (degrees)
% % nu = 0; %True anomaly (degrees)
a = 6678; %semimajor axis (km)
e = 0; %eccentricity
i = 51.6; %inclination (degrees)
O = 300.5; %Right ascencion of the right ascending node (degrees) %300 max 195
o = 0; %Argument of the perigee (degrees) %0 max 90
nu = 0; %True anomaly (degrees) %0

%Initialisation of date
year = 2020;
month = 1;
day = 1;
hours = 0;
minutes = 0;
seconds = 0;

EPS_orbit
E=sim('EPS_orbit');

%% CALCULATION beta angle
load('betadatamatrix.mat')

beta1=beta_data_matrix(:,1);
beta2=beta_data_matrix(:,2);
beta3=beta_data_matrix(:,3);
beta4=beta_data_matrix(:,4);
h=300;
e_f=0;

% plot(beta1)
for i=1:length(beta1)
    e_f(i)=eclipsefraction(h,beta1(i)*pi/180);
end
date=0:1/24:366;
figure()
set(gcf,'color','w');
    subplot(2,1,1)
    plot(date,beta1)
    legend('Beta angle [deg]')
    title('Beta angle, RAAN:0 degrees (1/1/20)')
    ylabel('Angle [degree]')
    xlabel('time in days')
    grid on
    subplot(2,1,2)
    plot(date,e_f,'r')
    legend('Eclipse Fraction')
    title('Eclipse duration as fraction of orbit period')
    ylabel('Fraction')
    xlabel('time in days')
    grid on

% h=300;
% beta=50;
% beta1(8779)
% a=eclipsefraction(h,beta)

% plot(beta2)
for i=1:length(beta2)
    e_f(i)=eclipsefraction(h,beta2(i)*pi/180);
end
date=0:1/24:366;
figure()
set(gcf,'color','w');
    subplot(2,1,1)
    plot(date,beta2)
    legend('Beta angle [deg]')
    title('Beta angle, RAAN: 90 degrees (1/1/20)')
    ylabel('Angle [degree]')
    xlabel('time in days')
    grid on
    subplot(2,1,2)
    plot(date,e_f,'r')
    legend('Eclipse Fraction')
    title('Eclipse duration as fraction of orbit period')
    ylabel('Fraction')
    xlabel('time in days')
    grid on
    
% plot(beta1)
for i=1:length(beta3)
    e_f(i)=eclipsefraction(h,beta3(i)*pi/180);
end
date=0:1/24:366;
figure()
set(gcf,'color','w');
    subplot(2,1,1)
    plot(date,beta3)
    legend('Beta angle [deg]')
    title('Beta angle, RAAN:180 degrees (1/1/20)')
    ylabel('Angle [degree]')
    xlabel('time in days')
    grid on
    subplot(2,1,2)
    plot(date,e_f,'r')
    legend('Eclipse Fraction')
    title('Eclipse duration as fraction of orbit period')
    ylabel('Fraction')
    xlabel('time in days')
    grid on
    
    
    
% plot(beta1)
for i=1:length(beta4)
    e_f(i)=eclipsefraction(h,beta4(i)*pi/180);
end
date=0:1/24:366;
figure()
set(gcf,'color','w');
    subplot(2,1,1)
    plot(date,beta4)
    legend('Beta angle [deg]')
    title('Beta angle, RAAN:270 degrees (1/1/20)')
    ylabel('Angle [degree]')
    xlabel('time in days')
    grid on
    subplot(2,1,2)
    plot(date,e_f,'r')
    legend('Eclipse Fraction')
    title('Eclipse duration as fraction of orbit period')
    ylabel('Fraction')
    xlabel('time in days')
    grid on