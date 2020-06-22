#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>

struct DateTime {
  std::string date;
  std::string time;

  std::string set_current_date_time();
  std::string set_current_date();
  std::string set_current_time();

  int compare_date_time(DateTime &other_date_time);
  int compare_time(DateTime &other_date_time);
  int compare_date(DateTime &other_date_time);
};

// Valores: data e horário
// Métodos: preencher a data e horário com os valores atuais
//          podendo fazer ambos ao mesmo tempo -> get_current_date_time()

#endif
