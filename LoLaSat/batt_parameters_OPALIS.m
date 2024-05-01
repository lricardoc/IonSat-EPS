%% E0

SoC = [1.0	0.9	0.8	0.7	0.6	0.5	0.4	0.3	0.2	0.1]';
E0 = [4.174	4.0437	3.93536	3.83785	3.73929	3.67334	3.63052	3.59078	3.51287	3.43506]';

%[p,S,mu] = polyfit(SoC,E0,4)
%[p,S,mu] = polyfit(SoC,E0,3)
%[p,S,mu] = polyfit(SoC,E0,2)

X = [ones(size(SoC)) SoC  (SoC).^2 (SoC).^3 (SoC).^4];
p2 = X\E0;


SoCd = [0.0:0.01:1];
%E0d=p(1)*SoCd.^4+p(2)*SoCd.^3+p(3)*SoCd.^2+p(4)*SoCd+p(5);
%E0d=p(1)*SoCd.^3+p(2)*SoCd.^2+p(3)*SoCd.^1+p(4);
%E0d=p(1)*SoCd.^2+p(2)*SoCd.^1+p(3);
E0d=p2(5)*SoCd.^4+p2(4)*SoCd.^3+p2(3)*SoCd.^2+p2(2)*SoCd+p2(1);

pt= [0 1.05 -2.11 2.45 2.8];
E0t=pt(1)*SoCd.^4+pt(2)*SoCd.^3+pt(3)*SoCd.^2+pt(4)*SoCd+pt(5);
%plot(SoCd,E0t)

figure()
set(gcf,'color','w');
plot(SoCd,E0d)
hold on, grid on
plot(SoC,E0,'x')
title('Open circuit voltage')
xlabel('State of Charge')
ylabel('E0 [V]')
legend('Polynomial fit','Measurement')
%plot(SoCd,E0t,'g')

%% R0
E0 = [4.174	4.0437	3.93536	3.83785	3.73929	3.67334	3.63052	3.59078	3.51287	3.43506]';
R0 = 0.65*[0.1146 0.114892 0.114196 0.114056 0.113996 0.112768 0.11452 0.114296 0.11816 0.12916]';

X = [ones(size(E0)) E0  (E0).^2 ];

r = X\R0;

E0d = (3.4:0.01:4.2)';
R0d = [ones(size(E0d))  E0d  (E0d).^2]*r;
rd=[0.0525 0.005 0.004 -2 3.6];
R0t = rd(1)+rd(2)*E0d+rd(3)*exp(rd(4)*(E0d-rd(5)));

figure()
set(gcf,'color','w');
%plot(E0d,R0d,'-',E0,R0,'o'), grid on, hold on
plot(E0,R0,'or'), grid on, hold on
%plot(SoC,R0,'or'), grid on, hold on
plot(E0d,R0t,'b')
%plot(SoCd,R0t,'b')
title('Internal Resistance')
xlabel('Open Circuit Voltage E0 [V]')
ylabel('R0 [Ω]')
xlim ([3.4 4.2])

%% R1
%clear all
SoC = [1.0	0.9	0.8	0.7	0.6	0.5	0.4	0.3	0.2	0.1]';
R1= [0.02114 0.031856 0.03816 0.032324 0.035504 0.045216 0.049808 0.043844 0.051928 0.059876]';

%[q,S,mu] = polyfit(SoC,R1,4)
X = [ones(size(SoC)) SoC  (SoC).^2 (SoC).^3 (SoC).^4];
q = X\R1;


SoCd = [0.0:0.01:1];
R1d=q(5)*SoCd.^4+q(4)*SoCd.^3+q(3)*SoCd.^2+q(2)*SoCd+q(1);

pt= [4.4 -10.39 8.47 -2.94 0.48];
E0t=pt(1)*SoCd.^4+pt(2)*SoCd.^3+pt(3)*SoCd.^2+pt(4)*SoCd+pt(5);
plot(SoCd,E0t)

figure()
set(gcf,'color','w');
plot(SoCd,R1d)
hold on
grid on
plot(SoC,R1,'x')
%plot(SoCd,E0t,'g')
title('Discharging Polarization Resistance')
xlabel('State of Charge')
ylabel('R1 [Ω]')

%% others
mean ([18.9	20.5	17.9	23.4	17.7])
mean ([4.7	3.8	3.2	3.5	3.3	3.6	3.7	4.1	2.7])