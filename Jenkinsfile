pipeline {
    agent any
    environment {
        NEXUS_USERNAME = credentials('nexus-creds')
        NEXUS_PASSWORD = credentials('nexus-creds')
        NEXUS_URL = 'http://localhost:8081'
        NEXUS_REPO = 'cpp-artifacts'
    }
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {
                bat 'make'
            }
        }
        stage('Test') {
            steps {
                echo 'Running tests...'
                bat 'parsexml.exe catalog.xml'
            }
        }
        stage('Upload to Nexus') {
            steps {
                bat """
                    curl -u %NEXUS_USERNAME%:%NEXUS_PASSWORD% --upload-file parsexml.exe ^
                        %NEXUS_URL%/repository/%NEXUS_REPO%/parsexml.exe
                """
            }
        }
    }
}
