import json

schedules = [
    "Tuesday 1",
    "Tuesday 2",
    "Wednesday 1",
    "Wednesday 2",
    "Thursday 1",
    "Thursday 2",
    "Friday 1",
    "Friday 2"
]

with open("pickup-data-orig.json", 'r') as file:
    data = json.load(file)

# # Open a new C++ file for writing
# with open('clean-data.cpp', 'w') as output_file:
#     # C++ code to print waste types based on schedule
#     output_file.write('#include <iostream>\n\n')
#     output_file.write('int main() {\n\t')
#     #parseFile(file)
#     output_file.write('\treturn 0;\n}')


for entry in data:
    collection_date = entry.get('CollectionDate')
    print(collection_date)
    # # Assuming '1' indicates pickup, '0' indicates no pickup
    # pickup_status = 1 if entry.get('Pickup') == 'Yes' else 0

    # # Extract week number from the date and update the array
    # week_number = int(collection_date.split('-')[1])
    # pickup_array[week_number - 1] = pickup_status
