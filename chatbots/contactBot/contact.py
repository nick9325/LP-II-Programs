import csv

def read_contacts():
    with open('contacts.csv', mode='r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        contacts = []
        for row in csv_reader:
            contacts.append(row)
        return contacts

def display_contact(contact):
    print(f"{contact['name']}\t{contact['phone']}\t{contact['email']}",end="")

def display_contacts(contacts):
    with open('contacts.csv', mode='r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for contact in csv_reader:
            print("{:<7} {:<10} {:<10}".format(contact[0],contact[1],contact[2]))

def search_contact(contacts):
    name = input("Enter name to search: ")
    found = False
    for contact in contacts:
        if contact['name'] == name:
            display_contact(contact)
            found = True
            break
    if not found:
        print("Contact not found.")
    print()

def sort_contacts_by_name(contacts):
    contacts.sort(key=lambda x: x['name'])

def sort_contacts_by_email(contacts):
    contacts.sort(key=lambda x: x['email'])

def main():
    contacts = read_contacts()
    print("Welcome to the Contact Management Chatbot!")
    print("What would you like to do?")
    print("1. View all contacts")
    print("2. Search for a contact")
    print("3. Sort contacts by name")
    print("4. Sort contacts by email")
    print("5. Exit")

    while True:
        choice = input("Enter your choice (1-5): ")
        if choice == '1':
            print("All contacts:")
            display_contacts(contacts)
        elif choice == '2':

            search_contact(contacts)
        elif choice == '3':
            sort_contacts_by_name(contacts)
            print("Contacts sorted by name.")
            print("{:<7} {:<10} {:<10}".format("name","phone","email"))
            for contact in contacts:
                print("{:<7} {:<10} {:<10}".format(contact["name"],contact["phone"],contact["email"]))
        elif choice == '4':
            sort_contacts_by_email(contacts)
            print("Contacts sorted by email.")
            print("{:<7} {:<10} {:<10}".format("name","phone","email"))
            for contact in contacts:
                print("{:<7} {:<10} {:<10}".format(contact["name"],contact["phone"],contact["email"]))
        elif choice == '5':
            print("Thank you for using the Contact Management Chatbot!")
            break
        else:
            print("Invalid choice. Please try again.")
        print('\n')
main()
           
