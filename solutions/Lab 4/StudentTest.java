import package4.Student;

public class StudentTest {
    public static void main(String[] args) {
        Student student1 = new Student(1, "John", "Smith");
        Student student2 = new Student(2, "Mary", "Jane");
        System.out.println(student1);
        System.out.println(student2);

        student1.setID(220503);
        student1.setFirstName("Ngân");
        student1.setLastName("Bùi Thị Thanh ");
        System.out.println(student1);
    }
}