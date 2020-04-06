//
// Created by sweethuman on 03.03.2020.
//

#ifndef LAB3_4_DOMAIN_H
#define LAB3_4_DOMAIN_H

typedef struct {
    char *name;
    int concentration;
    int quantity;
    int price;
} Medication;

/// Initializes Medication
/// \param model_name
/// \param concentration
/// \param quantity
/// \param price
/// \return
Medication *medication__create(char *name, int concentration, int quantity, int price);
/// Makes a copy of the given medication
/// \return a pointer to the newly created medication
Medication *medication__copy(Medication *medication);
void medication__destroy(Medication *medication);
/// Returns the Medication Name
/// \param medication medication to extract name from
/// \return A string
char *getMedicationName(Medication *medication);
/// Returns the Medication Concentration
/// \param medication medication to extract concentration from
/// \return a number
int getMedicationConcentration(Medication *medication);
/// Returns the Medication Quantity
/// \param medication medication to extract quantity from
/// \return a number
int getMedicationQuantity(Medication *medication);
/// Returns the Medication Price
/// \param medication medication to extract price from
/// \return a number
int getMedicationPrice(Medication *medication);

void testDomain();
#endif // LAB3_4_DOMAIN_H
