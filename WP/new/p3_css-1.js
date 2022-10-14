let b = document.getElementById("this") 

const c = `<h3>Computer Science and Engineering</h3>
<img src="cse.jpg">
<h3> Department Vision </h3>
<p>
    The vision of Department of Computer Science and Engineering is to recognize itself as globally renowned
    learning centre in the field of Computer Science & Engineering and foster the research and innovations
    for the global good.
</p>
<strong> Department Mission</strong>
<ul>
    <li>The mission of Department of Computer Science and Engineering is to:
    </li>
    <li>
        Impart education that encourages students to read critically, reason analytically, communicate
        persuasively, apply professionally and prepare them to excel in the field of computing.
    </li>
    <li>
        Imbibe strong-willed attitude in the students, research scholars and its own community to use their
        knowledge and skill-sets for the improvement of the society, country, and global community.
    </li>
    <li>
        Provide education based on ethical values resulting in knowledge and skills valued by industry and
        society.
    </li>
    <li>
        Impart training and create an environment that enables students and faculty members alike to engage
        in lifelong learning and pursuit of knowledge.
    </li>
</ul>`;

d = `<h3>Mechanical Engineering Department</h3>
<img src="mech.jpg">
<h3> Department Vision </h3>
<p>
    Department of Mechanical Engineering, Sardar Vallabhbhai National Institute of Technology, Surat
    perceives to be globally accepted center of quality technical education based on innovation and academic
    excellence
</p>
<strong> Department Mission</strong>
<p>Department of Mechanical Engineering, Sardar Vallabhbhai National Institute of Technology, Surat strives
    to disseminate technical knowledge to its undergraduate, post graduate and research scholars to meet
    intellectual, ethical and career challenges for sustainable growth of humanity, nation, and global
    community.</p>`

e = `<h3>Electrical Engineering Department</h3>
<img src="elec.jpg">
<h3> Department Vision </h3>
<p>
    To be the leading department disseminating globally acceptable education, effective industrial
    consultancy and relevant research output.
</p>
<strong> Department Mission</strong>
<p>
    To be a global centre of excellence in technical education and innovation producing competent
    professionals with integrity.</p>`

function cse() {
  b.innerHTML = c;
}

function med() {
  b.innerHTML = d ;
}

function eed(){
    b.innerHTML = e ;
}
