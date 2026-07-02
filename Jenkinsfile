pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe'
            }
        }

        stage('Test') {
            steps {
                bat '"C:\msys64\ucrt64\bin\g++.exe" test.cpp -o test.exe'
                bat 'test.exe'
            }
        }

        stage('Publish') {
            steps {
                echo 'Publicando artefacto generado...'
                archiveArtifacts artifacts: 'app.exe', fingerprint: true
            }
        }
    }
}
