pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {
        stage('Build') {
            steps {
                bat '"C:\msys64\ucrt64\bin\g++.exe" main.cpp -o app.exe'
            }
        }

        stage('Test') {
            steps {
                bat '"C:\msys64\ucrt64\bin\g++.exe" test.cpp -o test.exe'
                bat 'test.exe'
            }
        }

        stage('Analisis SonarCloud') {
            steps {
                withSonarQubeEnv('SonarCloud') {
                    bat 'sonar-scanner'
                }
            }
        }

        stage('Quality Gate') {
            steps {
                timeout(time: 5, unit: 'MINUTES') {
                    waitForQualityGate abortPipeline: true
                }
            }
        }

        stage('Publish') {
            steps {
                archiveArtifacts artifacts: 'app.exe', fingerprint: true
            }
        }
    }
}



