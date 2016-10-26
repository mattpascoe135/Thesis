%clean up from last usage
clear

SIZE = 1000;                    %size of the data array. Default to 1000

%Select the input files:
[filename,path] = uigetfile('*.*', 'Select a .s2p file for the input');
filepath1 = strcat(path, filename);
disp(filepath1);

[filename,path] = uigetfile('*.*', 'Select a .s2p file to remove from the input');
filepath2 = strcat(path, filename);
disp(filepath2);


%Open the data
fileID = fopen(filepath1,'r');
%Read the header of the .s2p file
for n = 1:8
    fgetl(fileID);
end
%Read through the input data and add it formatted into an array
j=1;
S=fgetl(fileID);
data = zeros(SIZE, 5);          %create empty array
while ischar(S)
    A=sscanf(S, '%f', [1 9]);       %get the data in INT form
    disp(A)

    sParam = [A(1)*10^9, A(2)+1i*A(3), A(4)+1i*A(5), A(6)+1i*A(7), A(8)+1i*A(9)];

    data(j,1) = sParam(1);          %get the frequency in GHz
    data(j,2) = sParam(2);          %get S11
    data(j,3) = sParam(3);          %get S12
    data(j,4) = sParam(4);          %get S21
    data(j,5) = sParam(5);          %get S22

    S=fgetl(fileID);                %get next set of data
    j=j+1;                          %increment pointer
end
input = data(1:j-1, :);              %resize array after finished
inputABCD = sParamToABCD(input);


%Open the data
fileID = fopen(filepath2,'r');
%Read the header of the .s2p file
for n = 1:8
    fgetl(fileID);
end
%Read through the input data and add it formatted into an array
j=1;
S=fgetl(fileID);
data = zeros(SIZE, 5);          %create empty array
while ischar(S)
    A=sscanf(S, '%f', [1 9]);       %get the data in INT form

    sParam = [A(1)*10^9, A(2)+1i*A(3), A(4)+1i*A(5), A(6)+1i*A(7), A(8)+1i*A(9)];

    data(j,1) = sParam(1);          %get the frequency in GHz
    data(j,2) = sParam(2);          %get S11
    data(j,3) = sParam(3);          %get S12
    data(j,4) = sParam(4);          %get S21
    data(j,5) = sParam(5);          %get S22

    S=fgetl(fileID);                %get next set of data
    j=j+1;                          %increment pointer
end
remove = data(1:j-1, :);              %resize array after finished
removeABCD = sParamToABCD(remove);

newMat = divData(input,remove);


%Plot the data 
figure;
X=data(1:j-1,1);


%Plot Return loss
subplot(2,2,1);
Y1=newMat(:,2);
Y2=input(:,2);
Y = 20*log10(abs(Y1));
plot(X,Y,'DisplayName','Fixed');
hold on; grid on;
subplot(2,2,1);
Y = 20*log10(abs(Y2));
plot(X,Y,'DisplayName','Original'); 
title('Return loss S11')
ylabel('Gain (dB)');
xlabel('Frequency (Hz)');
legend('show')


%Plot Insertion loss
subplot(2,2,3);
Y1=newMat(:,3);
Y2=input(:,3);
Y = 20*log10(abs(Y1));
plot(X,Y,'DisplayName','Fixed');
hold on; grid on;
subplot(2,2,3);
Y = 20*log10(abs(Y2));
plot(X,Y,'DisplayName','Original'); 
title('Isolation loss S12')
ylabel('Gain (dB)');
xlabel('Frequency (Hz)');
legend('show')


%Plot Insertion loss
subplot(2,2,2);
Y1=newMat(:,4);
Y2=input(:,4);
Y = 20*log10(abs(Y1));
plot(X,Y,'DisplayName','Fixed');
hold on; grid on; 
subplot(2,2,2);
Y = 20*log10(abs(Y2));
plot(X,Y,'DisplayName','Original'); 
title('Insertion loss S21')
ylabel('Gain (dB)');
xlabel('Frequency (Hz)');
legend('show')


%Plot Reflection loss
subplot(2,2,4);
Y1=newMat(:,5);
Y2=input(:,5);
Y = 20*log10(abs(Y1));
plot(X,Y,'DisplayName','Fixed');
hold on; grid on;
subplot(2,2,4);
Y = 20*log10(abs(Y2));
plot(X,Y,'DisplayName','Original'); 
title('Coupling loss S22')
ylabel('Gain (dB)');
xlabel('Frequency (Hz)');
legend('show')



fclose(fileID);