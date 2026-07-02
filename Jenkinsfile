pipeline {
    agent any

    stages {

        stage('Build') {
            steps {

                echo 'Compilando aplicacion principal...'

                bat '"C:\\gcc\\bin\\g++.exe" --coverage main.cpp -o app.exe'

            }
        }

        stage('Test') {
            steps {

                echo 'Compilando tests...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage test.cpp -o test.exe'

                bat 'test.exe > resultado-tests.txt'

                bat 'type resultado-tests.txt'
            }
        }

        stage('Publish') {
            steps {

                archiveArtifacts artifacts: 'app.exe,test.exe,resultado-tests.txt',
                                 fingerprint: true
            }
        }
    }

    post {

        success {
            echo 'Pipeline completada correctamente.'
        }

        failure {
            echo 'Pipeline fallida.'
        }

        always {
            echo 'Fin de la ejecucion.'
        }
    }
}
