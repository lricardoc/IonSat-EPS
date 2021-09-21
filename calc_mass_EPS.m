Lifetime=15;
Pav=6656.72;
Pav=1000;
Vbus=100;
Tmax=60;
Tmin=40;
Vbusmin=60;
Altitude=1000;
h=Altitude;
Peclipse=Pav;
DOD=20;


% First solar cells characteristics from Azurspace 3G30C
    Vdrop=2.5;       % Voltage drop in the bus of 2.5 Volts
    Tnom=28;         % nominal temperature in degrees C
    %Vmp=2.246       % nominal voltage for max Power V
    %Imp=0.4866      % nominal current for max Power A
    deltaVT=-0.0072; % change in voltage with temperature V/deg C
    deltaIT=0.00028; % change in current with temperature V/deg C
    Pmargin=10;      % margin in %
    Fluxavg=1367;    % Average solar flux in LEO  in W/m^2
    Fluxmin=1220;    % Worst solar flux
    alpha=14;        % angle in degrees
    FF=0.8;          % Fill factor
    CellS=0.0032;    % Total surface of cell in m^2
    CellAS=0.003018; % Active surface of cell in m^2
    Avmass=0.86;     % Average mass of solar array in kg/m^2

    % Calculating Vmp and Imp, nominal voltage, current, for max Power
    if Lifetime < 3.75
        Vmp=(-17.6*Lifetime+2411)/1000;
        Imp=(-0.32*Lifetime+504.4)/1000;
    else if Lifetime < 7.5
        Vmp=(-44/3*Lifetime+2400)/1000;
        Imp=(-2.08/3*Lifetime+505.8)/1000;
        end
    end
    if Lifetime>=7.5
        Vmp=(-17.6/3*Lifetime+2334)/1000;
        Imp=(-5.6/3*Lifetime+514.6)/1000;
%     else
%         print("error in lifetime");
    end

    % cell voltage at max temp
    VmpmaxT=(Vmp+deltaVT*(Tmax-Tnom));
% Number of cells in series:
    Nss=ceil( (Vbus+Vdrop)/VmpmaxT );
    % required current
    ImpminT=(Imp+deltaIT*(Tmin-Tnom));
    LF=cos(alpha*pi/180);
    Ireq=ImpminT*LF*Fluxmin/Fluxavg;
% Number of cells in parallel:
    Nsp=ceil((Pav*(1+Pmargin/100))/(Vbus*Ireq));
% Total surface of Solar Panel
    Asp=Nss*Nsp*CellAS/FF;
    MassSP=Asp*Avmass;

% BATTERY CALCULLATION
    Vbatmax=4.1 ;    % Maximum Battery voltage V
    Vbatmin=2.57;    % Minimum Battery voltage V
    Vmean=3.6;       % Mean Battery voltage V
    CAH=50;          % Battery nominal capacity in A*h
    eff=0.95;        % Battery efficiency
    mcell=1.1;       % Mass of a battery cell
    effrecharge=0.9; % Recharging efficiency

% Number of battery cells in series
    Nbs=floor(Vbus/Vbatmax);
    if Nbs*Vbatmin<Vbusmin
        Nbs=math.ceil(Vbusmin/Vbatmin);
        Vbdr=Nbs*Vmean;
    else
        Vbdr=Nbs*Vmean;  %Vbdr is an output also
    end
    
   h= Altitude;
% Orbit and Eclipse, assuming a circular orbit
    Torbit=2*pi*sqrt(((h+6378)^3)/398600)/60; %in minutes
    thetaecl=pi-2*acos(6378/(6378+h)); %this is in radians
    Teclipse=Torbit*thetaecl/(2*pi); %in minutes
% Calculation of capacity
    Ereq=Peclipse*Teclipse/60; %in Watt*hour
    Creq=Ereq/Vbdr;
    Cbat=CAH*eff*DOD/100;
% Number of battery cells in parallel
    Nbp=ceil(Creq/Cbat);
% Reserve energy
    Ereserve=Nbp*Vbdr*Cbat-Ereq;
    MassBat=Nbs*Nbp*mcell;

% recharge section
    Crecharge=Nbs*Nbp*CAH*DOD/100;
    Erecharge=Crecharge*Vbatmax;
    Precharge=Erecharge*60/(Torbit-Teclipse);
% Recharge section solar cells in series
    Nssr=ceil(Vbatmax*Nbs/VmpmaxT);
% Recharge section solar cells in parallel
    Ireq=Precharge/Vbdr;
    Nspr=ceil(Ireq/(effrecharge*ImpminT));
% Calculate surface and mass
    Aspx=Nssr*Nspr*CellAS/FF;
    MassSPx=Aspx*Avmass;

% Total mass and surface:
    Mpower=MassSP+MassSPx+MassBat
    Atotal=Asp+Aspx
    %return Nss,Nsp,Asp,MassSP, Nbs,Nbp,Ereserve,MassBat,Nssr,Nspr,Aspx,MassSPx
    %return Mpower,Atotal