function [E] = VbatDOD2(input)
% // Function for open circuit voltage calculation
% // inputs: DoD [-] - depth of discharge from 0 to 0.99
% //         Nbs [-] - number of battery cells in series
% // output: E [V] - battery open circuit voltage

% Li Ion 18650 battery
% min voltage: 2.75 V
% max voltage: 4.2 V
DoD = input(1);
Nbs = input(2);
% E=((-8.2816*DoD.^7+23.5749*DoD.^6-30*DoD.^5+23.7053*DoD.^4- ...
%         12.5877*DoD.^3+4.1315*DoD.^2-0.8658.*DoD)*4.4836 + 4.2)*Nbs;
E=((-8.2816*DoD.^7+23.5749*DoD.^6-30*DoD.^5+23.7053*DoD.^4- ...
        12.5877*DoD.^3+4.1315*DoD.^2-0.8658.*DoD)*4.4836 + 4.2)*Nbs;

end