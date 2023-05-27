import csv
from queue import PriorityQueue
  
q = PriorityQueue()

class Employee:
    def __init__(self, name, skills, productivity, teamwork, communication):
        self.name = name
        self.skills = skills
        self.productivity = productivity
        self.teamwork = teamwork
        self.communication = communication

class PerformanceEvaluator:
    def __init__(self):
        self.criteria = {
            'skills': 0.3,
            'productivity': 0.2,
            'teamwork': 0.25,
            'communication': 0.25
        }
    def evaluate_employee(self, employee):
        scores = {
            criterion: getattr(employee, criterion) * weight
            for criterion, weight in self.criteria.items()
        }
        overall_score = sum(scores.values())
        performance_level = self._determine_performance_level(overall_score)

        return [performance_level,overall_score]
    
    def _determine_performance_level(self, score):
        if score >= 0.8:
            return 'Outstanding'
        elif score >= 0.6:
            return 'Satisfactory'
        elif score >= 0.4:
            return 'Needs Improvement'
        else:
            return 'Unsatisfactory'

if __name__ == '__main__':
    evaluator = PerformanceEvaluator()
 
    while(True):
        
        print("\n1  : Show Emplyee's Details")
        print("2  : Evaluate Performance of Employee: ")
        print("3  : Overall Rankwise Performance")
        print("4  : Exit\n")
        
        user=int(input("Enter Your Choice: "))
        if(user==1):
            with open('C:/Users/nikhil/OneDrive/Desktop/other/AI_Programs/expert_system/data.csv', 'r') as file:
                reader = csv.reader(file)
                print("{:<3} {:<9} {:<6} {:<7} {:<14} {:<9} {:<14}".format("Id","Month","Name","Skills","Productivity","Teamwork","Communication"))
                for row in reader:
                    empid=row[0]
                    month=row[1]
                    name=row[2]
                    skills=row[3]
                    productivity=row[4]
                    teamwork=row[5]
                    communication=row[6]
                    print("{:<3} {:<9} {:<8} {:<8} {:<14} {:<9} {:<4}".format(empid,month,name,skills,productivity,teamwork,communication))
        elif(user==2):
            print("\nEnter Employee Id and Month to Evaluate Performance ")
            empid=input("Employee Id: ")
            month=input("Month: ")  
            with open('C:/Users/nikhil/OneDrive/Desktop/other/AI_Programs/expert_system/data.csv', 'r') as file:
                reader = csv.reader(file)
                for row in reader:
                    if(empid==row[0] and month==row[1]):
                        empid=row[0]
                        month=row[1]
                        name=row[2]
                        skills=float(row[3])
                        productivity=float(row[4])
                        teamwork=float(row[5])
                        communication=float(row[6])
        
                        employee1 = Employee(name, skills, productivity, teamwork, communication)
        
                        performance_level = evaluator.evaluate_employee(employee1)
        
                        print('\n')
                        print(f"Performance of {name} in {month}")
                        print(f"Overall Score: {performance_level[1]}")
                        print(f"Performance level: {performance_level[0]}")
                        print('\n')
                        
        elif(user==3):
            
            print("\nOverall  Rankwise Performance")
            with open('C:/Users/nikhil/OneDrive/Desktop/other/AI_Programs/expert_system/performs.csv', 'w', newline='') as file:
                writer = csv.writer(file)
                
                with open('C:/Users/nikhil/OneDrive/Desktop/other/AI_Programs/expert_system/data.csv', 'r') as file:
                    reader = csv.reader(file)
                    for row in reader:
                        empid=row[0]
                        month=row[1]
                        name=row[2]
                        skills=float(row[3])
                        productivity=float(row[4])
                        teamwork=float(row[5])
                        communication=float(row[6])
        
                        employee1 = Employee(name, skills, productivity, teamwork, communication)
        
                        performance_level = evaluator.evaluate_employee(employee1)
                        
                        writer.writerow([empid,name,performance_level[1],performance_level[0],month])
                
            with open('C:/Users/nikhil/OneDrive/Desktop/other/AI_Programs/expert_system/performs.csv', 'r') as file:
                reader = csv.reader(file)
                performs=[0.0]*10
                names=[""]*10
                perf=[""]*10
                for row in reader:
                    per=float(row[2])
                    performs[int(row[0])]+=per
                    names[int(row[0])]=row[1]
                    perf[int(row[0])]=row[3]
                    
                sorted_index=[]
                for i in range(0,10):
                    if(performs[i]!=0.0):
                        q.put((-(performs[i]/2),i))
                        
                        
                print("\nRank    Name    Score   Performance")
                i=1
                while(q.empty()==False):
                    idx=q.get()
                    print(f" {i}\t{names[idx[1]]}\t{'%.2f' %-idx[0]}\t{perf[idx[1]]}")
                    i+=1
        else:
            break 
                        
                
                
                        
                
                    
                    
                    
                    
                    
                
                
            
                
    
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
            
                
                        
                    
