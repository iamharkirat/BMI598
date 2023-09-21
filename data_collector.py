import serial
import csv
import time

# Configuration
# Change this to your Arduino's port (COM# for Windows, /dev/tty.* for macOS/Linux)
SERIAL_PORT = '/dev/cu.usbmodem11401'
BAUD_RATE = 115200
CSV_FILENAME = 'imu_data.csv'
COLLECTION_DURATION = 60  # Collect data for 1 minute

# Set up the serial connection
ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
time.sleep(2)  # Allow connection to establish

# Create/open the CSV file
with open(CSV_FILENAME, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)

    # Write the header
    csv_writer.writerow(["ax", "ay", "az", "gx", "gy", "gz", "timestamp"])

    # Start data collection
    start_time = time.time()
    while time.time() - start_time < COLLECTION_DURATION:
        # Read the line from serial
        line = ser.readline().decode('utf-8').strip()

        # Split and parse the values
        ax, ay, az, gx, gy, gz = map(float, line.split('\t'))
        current_time = time.time()

        # Write to CSV
        csv_writer.writerow([ax, ay, az, gx, gy, gz, current_time])

ser.close()
print("Data collection complete. Saved to", CSV_FILENAME)
