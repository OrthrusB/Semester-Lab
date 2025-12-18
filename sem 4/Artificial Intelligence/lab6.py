# def weather_forecast(sky, temperature, wind):
#     # Rule 1: If the sky is cloudy and there is no wind, then it might rain.
#     if sky == "cloudy" and wind == "none":
#         return "It might rain."
#     # Rule 2: If the temperature is below 0°C and the sky is clear, then it might snow.
#     if temperature < 0 and sky == "clear":
#         return "It might snow."
#     # Rule 3: If the temperature is above 30°C and there is no wind, then it might be a hot day.
#     if temperature > 30 and wind == "none":
#         return "It might be a hot day."
#     # Rule 4: If the sky is clear and there is wind, then it might be a pleasant day.
#     if sky == "clear" and wind == "windy":
#         return "It might be a pleasant day."
#     return "Weather conditions unclear, please check the forecast later."

# def main():
#     # Collect user inputs
#     sky = input("Enter the sky condition (cloudy/clear): ")
#     temperature = float(input("Enter the temperature in °C: "))
#     wind = input("Enter the wind condition (none/windy): ")
#     # Determine and print the weather forecast
#     forecast = weather_forecast(sky, temperature, wind)
#     print(forecast)

# main()


# def check_loan_eligibility(age, stable_income, credit_score, criminal_record, loan_default):
#     # Rule 1: If the applicant's age is between 18 and 65 and they have a stable income, then they are eligible for a loan.
#     if 18 <= age <= 65 and stable_income == "yes":
#         return "Eligible for a loan based on age and stable income."
#     # Rule 2: If the applicant has a credit score above 700, then they are eligible for a loan.
#     if credit_score > 700:
#         return "Eligible for a loan based on credit score."
#     # Rule 3: If the applicant has a criminal record, then they are not eligible for a loan.
#     if criminal_record == "yes":
#         return "Not eligible for a loan due to criminal record."
#     # Rule 4: If the applicant has defaulted on a loan before, then they are not eligible for a loan.
#     if loan_default == "yes":
#         return "Not eligible for a loan due to previous loan default."
#     # If none of the conditions are met, the applicant is not eligible for a loan.
#     return "Not eligible for a loan based on the given criteria."

# def main():
#     # Collect user inputs
#     age = int(input("Enter your age: "))
#     stable_income = input("Do you have a stable income? (yes/no): ")
#     credit_score = int(input("Enter your credit score: "))
#     criminal_record = input("Do you have a criminal record? (yes/no): ")
#     loan_default = input("Have you defaulted on a loan before? (yes/no): ")
#     # Determine and print the loan eligibility
#     eligibility = check_loan_eligibility(age, stable_income, credit_score, criminal_record, loan_default)
#     print(eligibility)

# main()

# def convert_to_24_hour(time_str):
#     """Converts time from 12-hour format (e.g., '2 PM') to 24-hour format."""
#     time_str = time_str.strip().upper()
#     if "AM" in time_str or "PM" in time_str:
#         time, period = time_str.split()
#         time = int(time)
#         if period == "PM" and time != 12:
#             time += 12
#         if period == "AM" and time == 12:
#             time = 0
#     else:
#         time = int(time_str)  # Assume it's already in 24-hour format
#     return time

# def simple_decision_making(time, is_weekday, is_sunny):
#     # Rule 1: If the time is between 6 AM and 8 AM and it's a weekday, then it's time to go to work.
#     if 6 <= time < 8 and is_weekday == "yes":
#         return "Time to go to work."
#     # Rule 2: If the time is between 12 PM and 1 PM, then it's time for lunch.
#     if 12 <= time <= 13:
#         return "Time for lunch."
#     # Rule 3: If the time is between 9 PM and 10 PM, then it's time to go to bed.
#     if 21 <= time < 23:
#         return "Time to go to bed."
#     # Rule 4: If it's the weekend and the weather is sunny, then go for a walk.
#     if is_weekday == "no" and is_sunny == "yes":
#         return "Go for a walk."
#     # If none of the conditions are met, return no specific action.
#     return "No specific action for this time."

# def main():
#     try:
#         # Collect user inputs
#         time_str = input("Enter the current time (e.g., '2 PM' or '14'): ")
#         time = convert_to_24_hour(time_str)
#         # Validate the time input
#         if time < 0 or time > 23:
#             raise ValueError("Time must be between 0 and 23.")
#         is_weekday = input("Is it a weekday? (yes/no): ").strip().lower()
#         is_sunny = input("Is the weather sunny? (yes/no): ").strip().lower()
#         # Ensure inputs are either 'yes' or 'no'
#         if is_weekday not in ['yes', 'no'] or is_sunny not in ['yes', 'no']:
#             raise ValueError("Input for 'is_weekday' and 'is_sunny' must be 'yes' or 'no'.")
#         # Determine and print the decision
#         decision = simple_decision_making(time, is_weekday, is_sunny)
#         print(decision)
#     except ValueError as e:
#         print(f"Error: {e}")

# if __name__ == "__main__":
#     main()

# def traffic_light_action(light_color, pedestrian_button):
#     """Determine the action based on the light color and pedestrian button status."""
#     # Rule 4: If the pedestrian button is pressed, then the light will turn red after a short delay.
#     if pedestrian_button == "yes":
#         return "The light will turn red after a short delay."
#     # Rule 1: If the light is red, then cars must stop.
#     if light_color == "red":
#         return "Cars must stop."
#     # Rule 2: If the light is green, then cars can go.
#     elif light_color == "green":
#         return "Cars can go."
#     # Rule 3: If the light is yellow, then cars must slow down and prepare to stop.
#     elif light_color == "yellow":
#         return "Cars must slow down and prepare to stop."
#     # If none of the conditions are met, return no specific action.
#     return "No specific action for the given light state."

# def main():
#     try:
#         # Collect user inputs
#         light_color = input("Enter the traffic light color (red, green, yellow): ").strip().lower()
#         pedestrian_button = input("Is the pedestrian button pressed? (yes/no): ").strip().lower()
        
#         # Validate light color input
#         if light_color not in ['red', 'green', 'yellow']:
#             print("Error: Light color must be 'red', 'green', or 'yellow'.")
#             return
#         # Validate pedestrian button input
#         if pedestrian_button not in ['yes', 'no']:
#             print("Error: Pedestrian button input must be 'yes' or 'no'.")
#             return
        
#         # Determine and print the traffic light action
#         action = traffic_light_action(light_color, pedestrian_button)
#         print(action)
#     except ValueError as e:
#         print(f"Error: {e}")

# if __name__ == "__main__":
#     main()

def smart_home_action(temperature, is_dark, at_home, security_armed, door_open):
    """Determine the action based on temperature, lighting, and security system status."""
    actions = []
    # Rule 1: If the temperature is below 18°C, then turn on the heater.
    if temperature < 18:
        actions.append("Turn on the heater.")
    # Rule 2: If the temperature is above 25°C, then turn on the air conditioner.
    if temperature > 25:
        actions.append("Turn on the air conditioner.")
    # Rule 3: If it is dark outside and someone is at home, then turn on the lights.
    if is_dark == "yes" and at_home == "yes":
        actions.append("Turn on the lights.")
    # Rule 4: If the security system is armed and a door is opened, then sound the alarm.
    if security_armed == "yes" and door_open == "yes":
        actions.append("Sound the alarm.")
    # If no actions are needed, return this message
    if not actions:
        actions.append("No specific action required.")
    return actions

def main():
    try:
        # Collect and validate user inputs
        temperature = float(input("Enter the current temperature in °C: "))
        is_dark = input("Is it dark outside? (yes/no): ").strip().lower()
        at_home = input("Is someone at home? (yes/no): ").strip().lower()
        security_armed = input("Is the security system armed? (yes/no): ").strip().lower()
        door_open = input("Is a door opened? (yes/no): ").strip().lower()

        valid_inputs = {'yes', 'no'}
        if is_dark not in valid_inputs or at_home not in valid_inputs or \
           security_armed not in valid_inputs or door_open not in valid_inputs:
            print("Error: All yes/no questions must be answered with 'yes' or 'no'.")
            return
        
        # Determine and print the smart home actions
        actions = smart_home_action(temperature, is_dark, at_home, security_armed, door_open)
        for action in actions:
            print(action)
    except ValueError as e:
        print(f"Error: Invalid input. Please ensure temperature is a number. {e}")

if __name__ == "__main__":
    main()
