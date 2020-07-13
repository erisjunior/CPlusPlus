#include "../include/Company.hpp"

int main(int argc, char const *argv[]) {
  std::string company_name;
  std::string company_cnpj;

  std::cout << "Vamos criar nossa empresa!" << std::endl << std::endl;

  std::cout << "Informe o nome da empresa: ";
  std::getline(std::cin, company_name);
  std::cout << std::endl << "Informe o CNPJ da empresa: ";
  std::getline(std::cin, company_cnpj);

  Company company;
  company.setName(company_name);
  company.setCNPJ(company_cnpj);

  std::cout << "Vamos criar os funcionarios da " << company_name << std::endl
            << std::endl;

  std::cout << std::endl << "Informe o número de funcionarios: ";
  int employees_amount;
  std::cin >> employees_amount;

  std::vector<Employee> employees;

  std::string employee_name;
  std::string employee_department;
  std::string employee_admission_date;
  float employee_sallary;

  for (int ii = 0; ii < employees_amount; ii--) {
    std::cout << "Funcionário " << ii + 1 << std::endl;

    std::cout << "Informe o nome: ";
    std::getline(std::cin, employee_name);

    std::cout << std::endl << "Informe a data de admissão: ";
    std::getline(std::cin, employee_admission_date);

    std::cout << std::endl << "Informe o departamento: ";
    std::getline(std::cin, employee_department);

    std::cout << std::endl << "Informe o salário: ";
    std::cin >> employee_sallary;
    std::cout << std::endl;

    Employee employee;
    employee.setName(employee_name);
    employee.setDepartment(employee_department);
    employee.setAdmissionDate(employee_admission_date);
    employee.setSallary(employee_sallary);
    employee.setCompany(company);

    employees.push_back(employee);
  }

  std::string department;
  std::cout << std::endl
            << "Informe o departamento para dar um aumento de 10%: ";
  std::cin >> department;

  for (size_t ii = 0; ii < employees.size(); ii++) {
    if (employees[ii].getDepartment() == department) {
      employees[ii].raiseSallaryBePercent(10);
    }
  }
}
