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

vector<Symptom> symptomData;
vector<Provider> providerData;
vector<UserRating> userRatings;

void initializeMockData() {
    Symptom s1;
    s1.name = "headache";
    s1.severity = 5;
    symptomData.push_back(s1);

    Symptom s2;
    s2.name = "fever";
    s2.severity = 8;
    symptomData.push_back(s2);

    Provider p1;
    p1.name = "Dr. Smith";
    p1.specialty = "Neurologist";
    p1.location = "New York";
    p1.schedule = "Monday, 10:00 AM";
    p1.rating = 4.5;
    providerData.push_back(p1);

    Provider p2;
    p2.name = "Dr. Johnson";
    p2.specialty = "General Physician";
    p2.location = "New York";
    p2.schedule = "Monday, 10:00 AM";
    p2.rating = 4.7;
    providerData.push_back(p2);

    UserRating r1;
    r1.providerName = "Dr. Smith";
    r1.rating = 4.5;
    userRatings.push_back(r1);

    UserRating r2;
    r2.providerName = "Dr. Johnson";
    r2.rating = 4.7;
    userRatings.push_back(r2);
}

vector<string> analyzeSymptoms(const vector<string>& userSymptoms) {
    vector<string> possibleIssues;
    for (size_t i = 0; i < userSymptoms.size(); ++i) {
        possibleIssues.push_back(userSymptoms[i]);
    }
    return possibleIssues;
}

vector<Provider> generateRecommendations(const vector<string>& userSymptoms, const string& userLocation, const string& userSchedule) {
    vector<Provider> matchedProviders;
    vector<string> possibleIssues = analyzeSymptoms(userSymptoms);

    for (size_t i = 0; i < providerData.size(); ++i) {
        if (find(possibleIssues.begin(), possibleIssues.end(), providerData[i].specialty) != possibleIssues.end() &&
            providerData[i].location == userLocation &&
            providerData[i].schedule == userSchedule) {
            matchedProviders.push_back(providerData[i]);
        }
    }

    sort(matchedProviders.begin(), matchedProviders.end(), [](const Provider& a, const Provider& b) -> bool {
        return a.rating > b.rating;
    });

    return matchedProviders;
}

void displayRecommendations(const vector<Provider>& recommendations) {
    cout << "Recommended Providers:" << endl;
    for (size_t i = 0; i < recommendations.size(); ++i) {
        cout << "Name: " << recommendations[i].name << ", Specialty: " << recommendations[i].specialty << ", Location: " << recommendations[i].location << ", Schedule: " << recommendations[i].schedule << ", Rating: " << recommendations[i].rating << endl;
    }
}

int main() {
    initializeMockData();

    vector<string> userSymptoms = {"Neurologist", "General Physician"};
    string userLocation = "New York";
    string userSchedule = "Monday, 10:00 AM";

    vector<Provider> recommendations = generateRecommendations(userSymptoms, userLocation, userSchedule);
    displayRecommendations(recommendations);

    return 0;
}
