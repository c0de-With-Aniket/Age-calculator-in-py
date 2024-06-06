from datetime import datetime

def calculate_age(birthdate_str, date_format="%Y-%m-%d"):
    
    try:
        birthdate = datetime.strptime(birthdate_str, date_format)
    except ValueError as e:
        return f"Error: {e}. Please ensure the date is in the correct format: {date_format}"

    today = datetime.today()
    
    
    age = today.year - birthdate.year
    
    
    if (today.month, today.day) < (birthdate.month, birthdate.day):
        age -= 1

    return age

def main():
    
    birthdate_str = input("Enter your birthdate (YYYY-MM-DD): ")
    age = calculate_age(birthdate_str)
    if isinstance(age, int):
        print(f"Your age is: {age} years")
    else:
        print(age)

if __name__ == "__main__":
    main()
