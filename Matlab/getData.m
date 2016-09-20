%clean up from last usage
clc
clear

SIZE = 1000;                    %size of the data array. Default to 1000


%SELECT:
filepath = cell(10,1);
k=1;
[filename,path] = uigetfile('*.*', 'Select a file. Press cancel to process');
while(filename ~= 0) 
    filepath{k} = strcat(path, filename);
    disp(filepath);
    [filename,path] = uigetfile('*.*', 'Select a file. Press cancel to process');
    k=k+1;
end


%READ:
data = zeros(SIZE, 5);          %create empty array
for l = 1:(k-1)
    %Open the data
    fileID = fopen(filepath{l},'r');

    %read the header of the .s2p file
    for n = 1:8
        fgetl(fileID);
    end

    %read through the data and add it formatted into an array
    j=1;
    S=fgetl(fileID);
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
    data = data(1:j-1, :);              %resize array after finished


    %PLOT the data
    X=data(:,1);

    %Plot Return loss
    subplot(2,2,1);
    Y=data(:,2);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('Return loss S11')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');

    %Plot Isolation loss
    subplot(2,2,3);
    Y=data(:,3);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('Isolation loss S12')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');

    %Plot Insertion loss
    subplot(2,2,2);
    Y=data(:,4);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('Insertion loss S21')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');

    %Plot Isolation loss
    subplot(2,2,4);
    Y=data(:,5);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('Coupling loss S22')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');

    fclose(fileID);
end
