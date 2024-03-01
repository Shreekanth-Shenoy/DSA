document.getElementById('bonusForm').addEventListener('submit', function(event) {
    event.preventDefault();

    var form = event.target;
    var formData = new FormData(form);

    fetch(form.action, {
        method: 'POST',
        body: formData
    })
    .then(response => response.text())
    .then(data => {
        document.getElementById('bonusResult').innerHTML = data;
    })
    .catch(error => {
        console.error('Error:', error);
    });
});
