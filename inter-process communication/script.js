const subjects = ["OS", "WAD", "DCN", "FLAT", "MSE"];
class Result {
    constructor(name, clas, rollno, marks, avg, grade) {
        this.name = name;
        this.clas = clas;
        this.rollno = rollno;
        this.marks = marks;
        this.avg = avg;
        this.grade = grade;
    }
}
let currentStudent = 1;
let studentMarks = [];

function displayTable() {
    let total_marks = 0;
    let table_content = `<div><table border="1">
        <tr>
            <th colspan="9">Grade Calculator</th>
        </tr>
        <tr>
            <th>Name</th>
            <th>Class</th>
            <th>Roll-no</th>
            <th>OS</th>
            <th>WAD</th>
            <th>DCN</th>
            <th>FLAT</th>
            <th>MSE</th>
            <th>Grade</th>
        </tr>
        `;

    for (let i = 0; i < currentStudent - 1; i++) {
        total_marks += studentMarks[i].avg;
        table_content += `<tr><td>${studentMarks[i].name}</td>
                <td>${studentMarks[i].clas}</td>
                <td>${studentMarks[i].rollno}</td>
                <td>${studentMarks[i].marks.OS}</td>
                <td>${studentMarks[i].marks.WAD}</td>
                <td>${studentMarks[i].marks.DCN}</td>
                <td>${studentMarks[i].marks.FLAT}</td>
                <td>${studentMarks[i].marks.MSE}</td>
                <td>${studentMarks[i].grade}</td>
                </tr>`;
    }
    table_content += `<tfoot><td colspan="3">Overall Grade</td>
        <td colspan="6">${calculateGrade(total_marks)}</td></tfoot>
    </table></div>`;

    return table_content;
}
function getDetails() {

    if (currentStudent == 6) {
        let body = document.getElementsByTagName("body");
        body[0].innerHTML = displayTable();
        return;
    }
    const name = document.getElementById("name").value;
    const clas = document.getElementById("class").value;
    const rollNo = document.getElementById("roll-no").value;
    const mark1 = parseInt(document.getElementById(subjects[0]).value);
    const mark2 = parseInt(document.getElementById(subjects[1]).value);
    const mark3 = parseInt(document.getElementById(subjects[2]).value);
    const mark4 = parseInt(document.getElementById(subjects[3]).value);
    const mark5 = parseInt(document.getElementById(subjects[4]).value);

    let marks = {
        "OS": mark1,
        "WAD": mark2,
        "DCN": mark3,
        "FLAT": mark4,
        "MSE": mark5,
    }

    let total = (mark1 + mark2 + mark3 + mark4 + mark5);
    let avg = total / 5;
    let grade = calculateGrade(avg)

    const result = new Result(name, clas, rollNo, marks, avg, grade);
    studentMarks.push(result);
    currentStudent++;
    document.getElementById("gradeForm").reset();
}

function calculateGrade(avg) {
    if (avg >= 90) {
        return 'S';
    } else if (avg >= 85 && avg < 90) {
        return 'A+';
    } else if (avg >= 80 && avg < 85) {
        return 'A';
    } else if (avg >= 75 && avg < 80) {
        return 'B+';
    } else if (avg >= 70 && avg < 75) {
        return 'B';
    } else if (avg >= 65 && avg < 70) {
        return 'C+';
    } else if (avg >= 60 && avg < 65) {
        return 'C';
    } else if (avg >= 55 && avg < 60) {
        return 'D';
    } else if (avg >= 50 && avg < 55) {
        return 'P';
    } else {
        return 'F';
    }
}

