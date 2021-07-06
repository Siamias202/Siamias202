package com.company;

 class customer {
    int age;
    String name;
    String address;

     public customer(int age, String name, String address) {
         this.age = age;
         this.name = name;
         this.address = address;
     }

     public int getAge() {
         return age;
     }

     public String getName() {
         return name;
     }

     public String getAddress() {
         return address;
     }
 }

class student extends customer
{
    int roll;
    String institution;

    public student(int age, String name, String address, int roll, String institution) {
        super(age, name, address);
        this.roll = roll;
        this.institution = institution;
    }

    public int getRoll() {
        return roll;
    }

    public String getInstitution() {
        return institution;
    }
}

class parents extends student
{
    int voter_id;
    String office_name;

    public parents(int age, String name, String address, int roll, String institution, int voter_id, String office_name) {
        super(age, name, address, roll, institution);
        this.voter_id = voter_id;
        this.office_name = office_name;
    }

    public int getVoter_id() {
        return voter_id;
    }

    public String getOffice_name() {
        return office_name;
    }
}
