%clean up from last usage
clear

%Select the input files:
[filename,path] = uigetfile('*.*', 'Select a .s2p file for the input');
filepath1 = strcat(path, filename);

[filename,path] = uigetfile('*.*', 'Select a .s2p file to remove from the input');
filepath2 = strcat(path, filename);

original = sparameters(filepath1);
cable = sparameters(filepath2);
freq = original.Frequencies;

tmp1 = s2t(original.Parameters);
tmp2 = s2t(cable.Parameters);
newMat = zeros(2, 2, 201);
for idx = 1:201
    mat1 = tmp1(:,:,idx);
    mat2 = tmp2(:,:,idx)^(-1);
    res = mat1 * mat2;
    newMat(:,:,idx) = res;
end
newMatS=t2s(newMat);
cable.Parameters = newMatS;

figure;
rfplot(cable)

figure;
rfplot(original)