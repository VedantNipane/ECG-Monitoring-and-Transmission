import csv
import scipy.io as sio
import pandas as pd

with open('ecg.csv', 'r') as input_file:
    reader = csv.reader(input_file)
    data = list(reader)

with open('ecg1.csv', 'w', newline='') as output_file:
    writer = csv.writer(output_file)
    writer.writerows(data[11:])


# Read CSV file into a Pandas DataFrame
df = pd.read_csv('ecg1.csv')

# Set the data type of 'data' row to float
df.loc[:] = df.values.astype(float)

# Set the sampling rate to 1000 Hz
samplingrate = 500

# Create a dictionary with the data and metadata
data_dict = {'ecg': df.values.T, 'samplingrate': samplingrate}

# Save the dictionary to a MATLAB .mat file
sio.savemat('ecg_m1.mat', data_dict)
