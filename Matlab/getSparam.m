function [data] = getSparam(file)
    fileID = fopen(file,'r');       %Open the data

    %read the header of the .s2p file
    for n = 1:8
        fgetl(fileID);
    end
    data = zeros(1000, 5);          %create empty array

    %read through the data and add it formatted into an array
    j=1;
    S=fgetl(fileID);
    while ischar(S)
        A=sscanf(S, '%f', [1 9]);       %get the data in INT form

        sParam = [A(1)*10^9, A(2)+1i*A(3), A(4)+1i*A(5), A(6)+1i*A(7), A(8)+1i*A(9)];

        %disp(sParam);
        
        data(j,1) = sParam(1);          %get the frequency in GHz
        data(j,2) = sParam(2);          %get S11
        data(j,3) = sParam(3);          %get S12
        data(j,4) = sParam(4);          %get S21
        data(j,5) = sParam(5);          %get S22

        S=fgetl(fileID);                %get next set of data
        j=j+1;                          %increment pointer
    end
    
    data = data(1:j-1, :);              %resize array after finished
    fclose(fileID);