clear
close

%Initialisation of date
date.year=2021;
date.month=3;
date.day=21;
date.hour=12;
date.minutes=0;
date.seconds=0;

%Orbit: Initialisation of Keplerian parameters
orbit.a = 6678e3;     %semimajor axis [m]
orbit.e = 0.001;     %eccentricity
orbit.i = 50;     %inclination [degrees]
orbit.O = 0;      %Right ascension of the right ascending node [degrees] %max 197, min 300.5 %181
orbit.o = 0;      %Argument of the perigee [degrees]                      %max 90, min 0      %90
orbit.nu = 0;       %True anomaly [degrees]

%time step based on gyro sampling frequency: 
TimeStep = 1;        %fixed-step size in solver, Default time step=0.25
Torbit=2*pi*sqrt((orbit.a/1e3)^3/(3.986004418E5));
N_orbits = 5;           %number of orbits to be simulated
%Time spent performing the simulation in seconds (one orbit is ~5400 s):
t_sim = N_orbits*Torbit;
%% get 1 power average
Psa=48;

Power=sim('testpropagator');

time = Power.tout;
Pcollected = getdatasamples(Power.Psa1,(1:length(time)));
beta = getdatasamples(Power.beta,(1:length(time)));

Pav=mean(Pcollected);
B=mean(beta);


%% get multiple power averages 1, for one orbit altitude, continues from previous section INCOMPLETE
Psa=48;

orbit.O=0;
paso=3;
maxRAAN=90;
N=maxRAAN/paso;
for i=1:N
    orbit.O = (i-1)*paso;
    RAAN(i)= orbit.O ;
    Power=sim('testpropagator');

    time = Power.tout;
    Pcollected = getdatasamples(Power.Psa1,(1:length(time)));
    beta = getdatasamples(Power.beta,(1:length(time)));

    Pav(i)=mean(Pcollected);
    B(i)=mean(beta);
end

% figure(1)
% subplot(2,1,1)
% plot(RAAN,B)
% subplot(2,1,2)
% plot(B,Pav)

figure(1)
set(gcf,'color','w');
    subplot(2,1,1)
        plot(RAAN,B)
        hold on;
        legend('RAAN vs Beta')
        %title('Power Generated')
        ylabel('Beta [deg]')
        xlabel('RAAN [deg]')
        grid on
    subplot(2,1,2)
        plot(B,Pav)
        hold on;
        legend('Beta vs Power Average')
        %title('Power Loads')
        ylabel('Power Average [W]')
        xlabel('Beta [deg]')
        %ylim([0,22])
        grid on
        
%% get multiple power averages 2 COMPLETE from 0 to 90, only 1 altitude
clear
close

%Initialisation of date
date.year=2021;
date.month=3;
date.day=21;
date.hour=12;
date.minutes=0;
date.seconds=0;

%Orbit: Initialisation of Keplerian parameters
orbit.a = 6678e3;     %semimajor axis [m]
orbit.e = 0.001;     %eccentricity
orbit.i = 50;     %inclination [degrees]
orbit.O = 0;      %Right ascension of the right ascending node [degrees] %max 197, min 300.5 %181
orbit.o = 0;      %Argument of the perigee [degrees]                      %max 90, min 0      %90
orbit.nu = 0;       %True anomaly [degrees]

%time step based on gyro sampling frequency: 
TimeStep = 1;        %fixed-step size in solver, Default time step=0.25
Torbit=2*pi*sqrt((orbit.a/1e3)^3/(3.986004418E5));
N_orbits = 5;           %number of orbits to be simulated
%Time spent performing the simulation in seconds (one orbit is ~5400 s):
t_sim = N_orbits*Torbit;

eff_Psa=0.95;
Psa=48*eff_Psa;

orbit.i=90;
orbit.O=0;
paso=1;
maxRAAN=90;
N=maxRAAN/paso;
for i=1:N+1
    orbit.O = (i-1)*paso;
    RAAN(i)= orbit.O ;
    Power=sim('testpropagator');

    time = Power.tout;
    Pcollected = getdatasamples(Power.Psa1,(1:length(time)));
    beta = getdatasamples(Power.beta,(1:length(time)));

    Pav(i)=mean(Pcollected);
    B(i)=mean(beta);
end

% figure(1)
% subplot(2,1,1)
% plot(RAAN,B)
% subplot(2,1,2)
% plot(B,Pav)

figure()
set(gcf,'color','w');
    subplot(2,1,1)
        plot(RAAN,B)
        hold on;
        legend('RAAN vs Beta')
        %title('Power Generated')
        ylabel('Beta [deg]')
        xlabel('RAAN [deg]')
        grid on
    subplot(2,1,2)
        plot(B,Pav)
        hold on;
        legend('Beta vs Power Average')
        %title('Power Loads')
        ylabel('Power Average [W]')
        xlabel('Beta [deg]')
        %ylim([0,22])
        grid on
        
%To get the average power value:
%vq1 = interp1(x,v,xq);
Pav1=10:0.1:40;
B1 = interp1(Pav,B,Pav1);
% figure()
% set(gcf,'color','w');
% plot(Pav1,B1)
% grid on

figure()
set(gcf,'color','w');
    subplot(2,1,1)
        plot(B,Pav)
        hold on;
        legend('Beta vs Power Average')
        %title('Power Loads')
        ylabel('Power Average [W]')
        xlabel('Beta [deg]')
        %ylim([0,22])
        grid on
    subplot(2,1,2)
        plot(Pav1,B1)
        grid on
        hold on;
        legend('Power Average vs Required Beta')
        %title('Power Loads')
        xlabel('Power Average [W]')
        ylabel('Beta [deg]')
        %ylim([0,22])
        grid on
        

%% get multiple power averages 3 (Changing the altitude, from 300 to 600km)
clear
close

%Initialisation of date
date.year=2021;
date.month=3;
date.day=21;
date.hour=12;
date.minutes=0;
date.seconds=0;

%Orbit: Initialisation of Keplerian parameters
%orbit.a = 6678e3;     %semimajor axis [m]

orbit.e = 0.001;     %eccentricity
orbit.i = 50;     %inclination [degrees]
orbit.O = 0;      %Right ascension of the right ascending node [degrees] %max 197, min 300.5 %181
orbit.o = 0;      %Argument of the perigee [degrees]                      %max 90, min 0      %90
orbit.nu = 0;       %True anomaly [degrees]



eff_Psa=0.95;
Psa=48*eff_Psa;

orbit.i=90;
orbit.O=0;
paso=1;
maxRAAN=90;
N=maxRAAN/paso;

for j=1:4
    orbit.a = (6371+200+j*100)*1e3;     %semimajor axis [m]
    %time step based on gyro sampling frequency: 
    TimeStep = 1;        %fixed-step size in solver, Default time step=0.25
    Torbit=2*pi*sqrt((orbit.a/1e3)^3/(3.986004418E5));
    N_orbits = 5;           %number of orbits to be simulated
    %Time spent performing the simulation in seconds (one orbit is ~5400 s):
    t_sim = N_orbits*Torbit;
for i=1:N+1
    orbit.O = (i-1)*paso;
    RAAN(i)= orbit.O ;
    Power=sim('testpropagator');

    time = Power.tout;
    Pcollected = getdatasamples(Power.Psa1,(1:length(time)));
    beta = getdatasamples(Power.beta,(1:length(time)));

    Pav(j,i)=mean(Pcollected);
    B(j,i)=mean(beta);
end
end

% figure()
% subplot(2,1,1)
% plot(RAAN,B)
% subplot(2,1,2)
% plot(B,Pav)

% figure()
% set(gcf,'color','w');
%     subplot(2,1,1)
%         plot(RAAN,B)
%         hold on;
%         legend('RAAN vs Beta')
%         %title('Power Generated')
%         ylabel('Beta [deg]')
%         xlabel('RAAN [deg]')
%         grid on     
%     subplot(2,1,2)
%         plot(B(1,:),Pav(1,:))
%         hold on;
%         plot(B(2,:),Pav(2,:),'r')
%         plot(B(3,:),Pav(3,:),'m')
%         plot(B(4,:),Pav(4,:),'c')
%         legend('Beta vs Power Average, 300km Altitude','Beta vs Power Average, 400km Altitude','Beta vs Power Average, 500km Altitude','Beta vs Power Average, 600km Altitude')
%         %title('Power Loads')
%         ylabel('Power Average [W]')
%         xlabel('Beta [deg]')
%         grid on
        
Pav1=10:0.1:40;
B1 = interp1(Pav(1,:),B(1,:),Pav1);     %Interpolation for altitude 300km
B2 = interp1(Pav(2,:),B(2,:),Pav1);
B3 = interp1(Pav(3,:),B(3,:),Pav1);
B4 = interp1(Pav(4,:),B(4,:),Pav1);


figure()
set(gcf,'color','w');
    subplot(2,1,1)
        plot(B(1,:),Pav(1,:))
        hold on;
        plot(B(2,:),Pav(2,:),'r')
        plot(B(3,:),Pav(3,:),'m')
        plot(B(4,:),Pav(4,:),'c')
        legend('Beta vs Power Average, 300km Altitude','Beta vs Power Average, 400km Altitude','Beta vs Power Average, 500km Altitude','Beta vs Power Average, 600km Altitude')
        %title('Power Loads')
        xlabel('Beta [deg]')
        ylabel('Power Average [W]')
        grid on   
    subplot(2,1,2)
        plot(Pav1,B1)   
        grid on
        hold on;
        plot(Pav1,B2,'r')
        plot(Pav1,B3,'m')
        plot(Pav1,B4,'c')
        legend('Average Power vs Required Beta, 300 km Altitude','Average Power vs Required Beta, 400 km Altitude','Average Power vs Required Beta, 500 km Altitude','Average Power vs Required Beta, 600 km Altitude')
        %title('Power Loads')
        xlabel('Average Power [W]')
        ylabel('Minimum Required Beta [deg]')
        %ylim([0,22])
        grid on
        
        
