function plotData(data)
    X=data(:,1);
    %Plot Return loss
    subplot(2,2,1);
    Y=data(:,2);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('S11')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');
    %Plot Isolation loss
    subplot(2,2,3);
    Y=data(:,3);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('S12')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');
    %Plot Insertion loss
    subplot(2,2,2);
    Y=data(:,4);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('S21')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');
    %Plot Isolation loss
    subplot(2,2,4);
    Y=data(:,5);
    plot(X,20 * log10(abs(Y)));
    hold on;
    title('S22')
    ylabel('Gain (dB)');
    xlabel('Frequency (Hz)');