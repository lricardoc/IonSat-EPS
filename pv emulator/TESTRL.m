function [RL,I1,P1,P2,P3] = testRL(R1,R2,R3,I,V)

RL=(R3.*(R1+R2))./(R1+R2+R3);
I3=V/R3;
I1=I-I3;
%I3=I-I1;
P1=I1^2.*R1;
P2=I1^2*R2;
P3=I3^2*R3;
end

