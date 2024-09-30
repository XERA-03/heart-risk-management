#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
using namespace std;
// Function to validate and get integer input within a specified rang
int getIntegerInput(const string& prompt, int minVal, int maxVal) {
    int input;
    while (true) {
        cout << prompt;
        if (!(cin >> input)) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (input < minVal || input > maxVal) {
            cout << "Input out of range. Please enter a number between " << minVal << " and " << maxVal << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return input;
}
// Function to validate and get string input from a list of options
string getStringInput(const string& prompt, const string& option1, const string& option2, const string& option3) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (input != option1 && input != option2 && input != option3) {
            cout << "Invalid input. Please enter '" << option1 << "', '" << option2 << "', or '" << option3 << "'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return input;
}
// Function to calculate BMI using height in centimeters and weight in kilograms
double calculateBMI(double heightCM, double weightKG) {
    double heightMeters = heightCM / 100.0; // Convert height to meters
    return weightKG / (heightMeters * heightMeters); // BMI formula
}
// Function to calculate BMI category
string calculateBMICategory(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 25.0) {
        return "Normal weight";
    } else if (bmi < 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
}
// Function to calculate heart attack risk based on various factors
double calculateHeartAttackRisk(int age, int cholesterol, int hdl, int ldl, int bloodPressure, int stressLevel, int physicalActivityLevel, int gender, double& heightCM, double& weightKG) {
    double risk = 0.0;
    int totalFactors = 20; // Total number of risk factors considered (including gender)
    // Age factor
    if (age >= 45) {
        risk += 1.0;
    }
    // Cholesterol factor (using both HDL and LDL)
    if (cholesterol >= 200) {
        risk += 1.0;
    }
    // HDL cholesterol factor
    if (hdl < 40) { // HDL should ideally be 40 mg/dL or higher
        risk += 1.0;
    }
    // LDL cholesterol factor
    if (ldl >= 160) { // LDL should ideally be below 160 mg/dL
        risk += 1.0;
    }
    // Blood pressure factor
    if (bloodPressure >= 140) {
        risk += 1.0;
    }
    // Additional factors (15 in total excluding gender)
    // Factor 6: Family history of heart disease
    int familyHistory;
    cout << "Family history of heart disease? (1 for yes, 0 for no): ";
    familyHistory = getIntegerInput("", 0, 1);
    if (familyHistory == 1) {
        risk += 1.0;
    }
    // Factor 7: Smoking habits
    int smoking;
    cout << "Are you a smoker? (1 for yes, 0 for no): ";
    smoking = getIntegerInput("", 0, 1);
    if (smoking == 1) {
        risk += 1.0;
    }
    // Factor 8: Diabetes
    int diabetes;
    cout << "Do you have diabetes? (1 for yes, 0 for no): ";
    diabetes = getIntegerInput("", 0, 1);
    if (diabetes == 1) {
        risk += 1.0;
    }
    // Factor 9: Stress level
    if (stressLevel >= 7) { // High stress if stress level is 7 or higher
        risk += 1.0;
    }
    // Factor 10: Alcohol consumption
    int alcoholConsumption;
    cout << "Do you consume alcohol regularly? (1 for yes, 0 for no): ";
    alcoholConsumption = getIntegerInput("", 0, 1);
    if (alcoholConsumption == 1) {
        risk += 1.0;
    }
    // Factor 11: Occupational hazards
    int occupationalHazards;
    cout << "Are you exposed to occupational hazards (e.g., chemicals, pollutants)? (1 for yes, 0 for no): ";
    occupationalHazards = getIntegerInput("", 0, 1);
    if (occupationalHazards == 1) {
        risk += 1.0;
    }
    // Factor 12: Physical activity level
    if (physicalActivityLevel == 3) { // High physical activity
        risk -= 1.0; // Lower risk for high physical activity
    } else if (physicalActivityLevel == 1) { // Low physical activity
        risk += 1.0; // Higher risk for low physical activity
    }
    // Factor 13: BMI factor (calculated outside this function now)
    double bmi = calculateBMI(heightCM, weightKG);
    if (bmi >= 30.0) { // BMI 30 or higher considered a risk factor
        risk += 1.0;
    }
    // Factor 14: Diet factor (e.g., high saturated fat intake)
    // To be implemented based on dietary assessment

    // Factor 15: Ethnicity-specific risk factors (optional)
    // To be implemented based on ethnicity data

    // Calculate risk percentage
    double riskPercentage = (risk / totalFactors) * 100.0;
    return riskPercentage;
}
// Function to display risk categories based on risk percentage
void displayRiskAssessment(double riskPercentage, double bmi) {
    cout << fixed << setprecision(2);
    cout << "Your heart attack risk percentage: " << riskPercentage << "%" << endl;
    cout << "Your BMI: " << bmi << " (" << calculateBMICategory(bmi) << ")" << endl;

    // Define risk categories based on risk percentage
    if (riskPercentage < 25.0) {
        cout << "Your risk level is low." << endl;
    } else if (riskPercentage < 50.0) {
        cout << "Your risk level is moderate." << endl;
    } else {
        cout << "Your risk level is high." << endl;
    }
}
// Main function
int main() {
    int age, cholesterol, hdl, ldl, bloodPressure, stressLevel, physicalActivityLevel, gender;
    string physicalActivity;
    double heightCM, weightKG;

    cout << "Welcome to the Heart Attack Risk Assessment Program." << endl;

    age = getIntegerInput("Enter your age: ", 1, numeric_limits<int>::max());

    cholesterol = getIntegerInput("Enter your total cholesterol level (mg/dL): ", 0, numeric_limits<int>::max());

    hdl = getIntegerInput("Enter your HDL cholesterol level (mg/dL): ", 0, numeric_limits<int>::max());

    ldl = getIntegerInput("Enter your LDL cholesterol level (mg/dL): ", 0, numeric_limits<int>::max());

    bloodPressure = getIntegerInput("Enter your blood pressure (mmHg): ", 0, numeric_limits<int>::max());

    stressLevel = getIntegerInput("Enter your stress level (1 to 10): ", 1, 10);

    physicalActivity = getStringInput("Enter your physical activity level ('low', 'moderate', 'high'): ", "low", "moderate", "high");
    if (physicalActivity == "low") {
        physicalActivityLevel = 1;
    } else if (physicalActivity == "moderate") {
        physicalActivityLevel = 2;
    } else {
        physicalActivityLevel = 3;
    }

    gender = getIntegerInput("Enter your gender (1 for male, 0 for female): ", 0, 1);

    heightCM = getIntegerInput("Enter your height in centimeters: ", 1, numeric_limits<int>::max());
    weightKG = getIntegerInput("Enter your weight in kilograms: ", 1, numeric_limits<int>::max());

    double riskPercentage = calculateHeartAttackRisk(age, cholesterol, hdl, ldl, bloodPressure, stressLevel, physicalActivityLevel, gender, heightCM, weightKG);

    displayRiskAssessment(riskPercentage, calculateBMI(heightCM, weightKG));

    return 0;
}

