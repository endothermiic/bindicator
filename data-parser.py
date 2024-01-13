import json

schedules = []
first_entry = 1

first_day = "monday"  # Should reset after every year - change the start date

with open("pickup-data-orig.json", 'r') as file:
    data = json.load(file)

# Open a new C++ file for writing
with open('clean-data.cpp', 'w') as output_file:
    output_file.write('#include <iostream>\n\n')
    output_file.write('int main() {\n\t')
    # loop over input data and initialize arrays
    for entry in data:
        schedule = entry.get("Schedule")
        if schedule in schedules:
            output_file.write(', ')
        if schedule not in schedules:
            if not first_entry:
                output_file.write('};\n\t')
            output_file.write(
                'int ' + schedule.replace(" ", "") + '[] = {')
            schedules.append(schedule)
            first_entry = 0

        organics = 0 if entry.get("Organics") == '0' else 1
        garbage = 0 if entry.get("Garbage") == '0' else 1
        recycling = 0 if entry.get("Recycling") == '0' else 1
        yard_waste = 0 if entry.get("YardWaste") == '0' else 1

        output_file.write(str(organics*1000 + garbage*100 +
                          recycling*10 + yard_waste))

    output_file.write('};\nreturn 0;\n}')
    output_file.close()
