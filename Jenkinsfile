pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {

        stage('Build') {
            steps {
                echo 'Compilando aplicación principal...'
                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" main.cpp -o app.exe'
            }
        }

        stage('Test') {
            steps {
                echo 'Compilando y ejecutando tests...'
                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" test.cpp -o test.exe'
                bat 'test.exe > resultado-tests.txt'
                bat 'type resultado-tests.txt'
            }
        }

        stage('Analisis SonarCloud') {
            steps {
                echo 'Ejecutando análisis SonarCloud...'
                withSonarQubeEnv('SonarCloud') {
                    bat '"C:\\sonar-scanner\\bin\\sonar-scanner.bat"'
                }
            }
        }

        stage('Quality Gate') {
            steps {
                echo 'Comprobando Quality Gate...'
                timeout(time: 5, unit: 'MINUTES') {
                    waitForQualityGate abortPipeline: true
                }
            }
        }

        stage('Publish') {
            steps {
                echo 'Publicando artefactos...'
                archiveArtifacts artifacts: 'app.exe,test.exe,resultado-tests.txt', fingerprint: true
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

        unstable {
            echo 'Pipeline inestable.'
        }

        always {
            echo 'Fin de la ejecución.'
        }
    }
}
