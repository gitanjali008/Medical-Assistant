#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Symptom {
    string name;
    int severity;
};

struct Provider {
    string name;
    string specialty;
    string location;
    string schedule;
    float rating;
};

struct UserRating {
    string providerName;
    float rating;
};

vector<Symptom> symptomData = {
    {"headache", 5},
    {"fever", 8},
    {"cough", 6},
    {"cold", 9},
    {"nausea", 4}
};

vector<Provider> providerData = {
    {"Dr. Smith", "Neurologist", "New York", "Monday, 10:00 AM", 4.5},
    {"Dr. Johnson", "General Physician", "New York", "Monday, 10:00 AM", 4.7},
    {"Dr. Jain", "Psycologist", "New York", "Monday, 10:00 AM", 4.3},
};

vector<UserRating> userRatings = {
    {"Dr. Smith", 4.5},
    {"Dr. Johnson", 4.7},
    {"Dr. Jain", 4.3}
};

vector<string> analyzeSymptoms(const vector<string>& userSymptoms) {
    vector<string> possibleIssues;
    for (const auto& symptom : userSymptoms) {
        for (const auto& provider : providerData) {
            if (provider.specialty == symptom) {
                possibleIssues.push_back(symptom);
                break;
            }
        }
    }
    return possibleIssues;
}

vector<Provider> generateRecommendations(const vector<string>& userSymptoms, const string& userLocation, const string& userSchedule) {
    vector<Provider> matchedProviders;
    vector<string> possibleIssues = analyzeSymptoms(userSymptoms);

    for (const auto& provider : providerData) {
        if (find(possibleIssues.begin(), possibleIssues.end(), provider.specialty) != possibleIssues.end() &&
            provider.location == userLocation &&
            provider.schedule == userSchedule) {
            matchedProviders.push_back(provider);
        }
    }

    sort(matchedProviders.begin(), matchedProviders.end(), [](const Provider& a, const Provider& b) {
        return a.rating > b.rating;
    });

    return matchedProviders;
}

void displayRecommendations(const vector<Provider>& recommendations) {
    cout << "Recommended Providers:" << endl;
    for (const auto& provider : recommendations) {
        cout << "Name: " << provider.name << ", Specialty: " << provider.specialty << ", Location: " << provider.location << ", Schedule: " << provider.schedule << ", Rating: " << provider.rating << endl;
    }
}

int main() {
    vector<string> userSymptoms = {"headache", "fever"};
    string userLocation = "New York";
    string userSchedule = "Monday, 10:00 AM";

    vector<Provider> recommendations = generateRecommendations(userSymptoms, userLocation, userSchedule);
    displayRecommendations(recommendations);

    return 0;
}
