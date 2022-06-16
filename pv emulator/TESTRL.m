function [RL,R3,I1,P1,P2,P3] = TESTRL(R1,R2, I, V)

RL=V/I;
R3=(RL*(R1+R2))/(R1+R2-RL);
%V=I*RL;
I3=V/R3;
I1=I-I3;
%I3=I-I1;
P1=I1^2*R1;
P2=I1^2*R2;
P3=I3^2*R3;
end

